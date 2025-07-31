#include "x11_window.hpp"

#include <X11/Xatom.h>
#include <X11/cursorfont.h>
#include <X11/extensions/Xfixes.h>
#include <X11/extensions/shape.h>

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>

namespace connmap {

X11Window::X11Window(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    : location_x(x), location_y(y), size_x(width), size_y(height) {}

X11Window::~X11Window() {
  if (normal_cursor) XFreeCursor(display, normal_cursor);
  if (drag_cursor) XFreeCursor(display, drag_cursor);
  if (display) XCloseDisplay(display);
}

bool X11Window::init() {
  display = XOpenDisplay(nullptr);
  if (!display) {
    std::cerr << "Cannot connect to X server\n";
    return false;
  }

  int screen = XDefaultScreen(display);
  Window root = DefaultRootWindow(display);

  if (!XMatchVisualInfo(display, screen, 32, TrueColor, &vinfo)) {
    std::cerr << "No suitable visual found\n";
    return false;
  }

  XSetWindowAttributes attrs;
  attrs.colormap = XCreateColormap(display, root, vinfo.visual, AllocNone);
  attrs.background_pixel = 0;
  attrs.border_pixel = 0;
  attrs.background_pixmap = None;
  attrs.override_redirect = True;

  unsigned long value_mask =
      CWColormap | CWBackPixel | CWBorderPixel | CWBackPixmap;

  // Check if we should disable override redirect for certain DEs
  bool disable_override_redirect = false;
  std::string desktop = getDesktopEnvironment();
  if (!desktop.empty()) {
    std::transform(desktop.begin(), desktop.end(), desktop.begin(), ::tolower);
    const std::vector<std::string> de_list = {
        "kde",  "gnome",         "xfce",   "lxde",    "lxqt",
        "mate", "enlightenment", "deepin", "cinnamon"};

    for (const auto& de : de_list) {
      if (desktop.find(de) != std::string::npos) {
        disable_override_redirect = true;
        break;
      }
    }
  }

  if (!disable_override_redirect) {
    value_mask |= CWOverrideRedirect;
  }

  window =
      XCreateWindow(display, root, location_x, location_y, size_x, size_y, 0,
                    vinfo.depth, InputOutput, vinfo.visual, value_mask, &attrs);

  if (!window) {
    std::cerr << "Failed to create window\n";
    return false;
  }

  // Set window properties
  if (disable_override_redirect) {
    setupWindowPropertiesForDE();
  } else {
    setupWindowPropertiesForWM();
  }

  // Create cursors
  normal_cursor = XCreateFontCursor(display, XC_left_ptr);
  drag_cursor = XCreateFontCursor(display, XC_fleur);
  XDefineCursor(display, window, normal_cursor);

  // Set class hint
  XClassHint* xch = XAllocClassHint();
  xch->res_name = const_cast<char*>("connmap");
  xch->res_class = const_cast<char*>("connmap");
  XSetClassHint(display, window, xch);
  XFree(xch);

  // Select input events
  XSelectInput(display, window,
               ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

  // Map the window
  XMapWindow(display, window);

  // Lower window if using override redirect
  if (!disable_override_redirect) {
    XLowerWindow(display, window);
  }

  return true;
}

void X11Window::setupWindowPropertiesForDE() {
  Atom window_type = XInternAtom(display, "_NET_WM_WINDOW_TYPE", False);

  if (isDesktopEnvironment()) {
    // Use desktop type for desktop environments to stay at bottom layer
    Atom window_type_desktop =
        XInternAtom(display, "_NET_WM_WINDOW_TYPE_DESKTOP", False);
    XChangeProperty(display, window, window_type, XA_ATOM, 32, PropModeReplace,
                    (unsigned char*)&window_type_desktop, 1);

    // Set window states
    Atom window_state = XInternAtom(display, "_NET_WM_STATE", False);
    Atom window_state_below =
        XInternAtom(display, "_NET_WM_STATE_BELOW", False);
    Atom window_state_sticky =
        XInternAtom(display, "_NET_WM_STATE_STICKY", False);
    Atom window_state_skip_taskbar =
        XInternAtom(display, "_NET_WM_STATE_SKIP_TASKBAR", False);
    Atom window_state_skip_pager =
        XInternAtom(display, "_NET_WM_STATE_SKIP_PAGER", False);

    Atom states[] = {window_state_below, window_state_sticky,
                     window_state_skip_taskbar, window_state_skip_pager};

    XChangeProperty(display, window, window_state, XA_ATOM, 32, PropModeReplace,
                    (unsigned char*)states, 4);

    // Set strut partial (no reserved space)
    Atom strut_partial = XInternAtom(display, "_NET_WM_STRUT_PARTIAL", False);
    unsigned long strut[12] = {0};
    XChangeProperty(display, window, strut_partial, XA_CARDINAL, 32,
                    PropModeReplace, (unsigned char*)strut, 12);
  } else {
    // Use desktop type for window managers
    Atom window_type_desktop =
        XInternAtom(display, "_NET_WM_WINDOW_TYPE_DESKTOP", False);
    XChangeProperty(display, window, window_type, XA_ATOM, 32, PropModeReplace,
                    (unsigned char*)&window_type_desktop, 1);
  }

  // Set opacity to 0.99 to ensure proper compositing
  double alpha = 0.99;
  unsigned long opacity = (unsigned long)(0xFFFFFFFFul * alpha);
  Atom window_opacity = XInternAtom(display, "_NET_WM_WINDOW_OPACITY", False);
  XChangeProperty(display, window, window_opacity, XA_CARDINAL, 32,
                  PropModeReplace, (unsigned char*)&opacity, 1);
}

void X11Window::setupWindowPropertiesForWM() {
  // For basic window managers, just ensure the window stays in background
  // Override redirect is already set
}

bool X11Window::isDesktopEnvironment() const {
  std::string desktop = getDesktopEnvironment();
  if (desktop.empty()) return false;

  std::transform(desktop.begin(), desktop.end(), desktop.begin(), ::tolower);
  const std::vector<std::string> de_list = {
      "kde",  "gnome",         "xfce",   "lxde",    "lxqt",
      "mate", "enlightenment", "deepin", "cinnamon"};

  for (const auto& de : de_list) {
    if (desktop.find(de) != std::string::npos) {
      return true;
    }
  }

  return false;
}

std::string X11Window::getDesktopEnvironment() const {
  const char* xdg_desktop = std::getenv("XDG_CURRENT_DESKTOP");
  if (xdg_desktop && std::strlen(xdg_desktop) > 0) {
    return std::string(xdg_desktop);
  }
  return "";
}

void X11Window::processEvents() {
  XEvent event;

  while (XPending(display)) {
    XNextEvent(display, &event);

    switch (event.type) {
      case ButtonPress:
        if (event.xbutton.button == Button1) {
          is_dragging = true;
          drag_start_x = event.xbutton.x_root;
          drag_start_y = event.xbutton.y_root;

          Window child;
          XTranslateCoordinates(display, window, DefaultRootWindow(display), 0,
                                0, &window_start_x, &window_start_y, &child);

          setDragCursor();
        }
        break;

      case ButtonRelease:
        if (event.xbutton.button == Button1) {
          is_dragging = false;
          setNormalCursor();
        }
        break;

      case MotionNotify:
        if (is_dragging) {
          int delta_x = event.xmotion.x_root - drag_start_x;
          int delta_y = event.xmotion.y_root - drag_start_y;

          XMoveWindow(display, window, window_start_x + delta_x,
                      window_start_y + delta_y);
        }
        break;
    }
  }
}

void X11Window::setNormalCursor() {
  XDefineCursor(display, window, normal_cursor);
}

void X11Window::setDragCursor() { XDefineCursor(display, window, drag_cursor); }

}  // namespace connmap