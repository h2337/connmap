#include "x11.h"

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xfixes.h>
#include <X11/extensions/shape.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESKTOP_NAME_LEN 256
#define WINDOW_OPACITY_DEFAULT 0.99

static const char *supported_desktop_environments[] = {
    "kde",  "gnome",         "xfce",   "lxde",    "lxqt",
    "mate", "enlightenment", "deepin", "cinnamon"};

static const int num_supported_desktops =
    sizeof(supported_desktop_environments) /
    sizeof(supported_desktop_environments[0]);

static bool is_supported_desktop_environment(const char *desktop) {
  if (!desktop || !*desktop) {
    return false;
  }

  char desktop_lower[MAX_DESKTOP_NAME_LEN];
  strncpy(desktop_lower, desktop, sizeof(desktop_lower) - 1);
  desktop_lower[sizeof(desktop_lower) - 1] = '\0';

  for (char *p = desktop_lower; *p; ++p) {
    *p = tolower(*p);
  }

  for (int i = 0; i < num_supported_desktops; i++) {
    if (strstr(desktop_lower, supported_desktop_environments[i]) != NULL) {
      return true;
    }
  }

  return false;
}

static bool setup_window_properties(Display *display, Window window,
                                    bool is_desktop_environment) {
  Atom window_type = XInternAtom(display, "_NET_WM_WINDOW_TYPE", False);
  if (window_type == None) {
    fprintf(stderr, "Failed to get _NET_WM_WINDOW_TYPE atom\n");
    return false;
  }

  if (is_desktop_environment) {
    Atom window_type_normal =
        XInternAtom(display, "_NET_WM_WINDOW_TYPE_NORMAL", False);
    if (window_type_normal == None) {
      fprintf(stderr, "Failed to get _NET_WM_WINDOW_TYPE_NORMAL atom\n");
      return false;
    }

    if (XChangeProperty(display, window, window_type, XA_ATOM, 32,
                        PropModeReplace, (unsigned char *)&window_type_normal,
                        1) != Success) {
      fprintf(stderr, "Failed to set window type to normal\n");
      return false;
    }

    Atom window_state = XInternAtom(display, "_NET_WM_STATE", False);
    Atom window_state_below =
        XInternAtom(display, "_NET_WM_STATE_BELOW", False);
    Atom window_state_sticky =
        XInternAtom(display, "_NET_WM_STATE_STICKY", False);
    Atom window_state_skip_taskbar =
        XInternAtom(display, "_NET_WM_STATE_SKIP_TASKBAR", False);
    Atom window_state_skip_pager =
        XInternAtom(display, "_NET_WM_STATE_SKIP_PAGER", False);

    if (window_state == None || window_state_below == None ||
        window_state_sticky == None || window_state_skip_taskbar == None ||
        window_state_skip_pager == None) {
      fprintf(stderr, "Failed to get window state atoms\n");
      return false;
    }

    Atom states[] = {window_state_below, window_state_sticky,
                     window_state_skip_taskbar, window_state_skip_pager};

    if (XChangeProperty(display, window, window_state, XA_ATOM, 32,
                        PropModeReplace, (unsigned char *)states,
                        4) != Success) {
      fprintf(stderr, "Failed to set window states\n");
      return false;
    }

    Atom strut_partial = XInternAtom(display, "_NET_WM_STRUT_PARTIAL", False);
    if (strut_partial != None) {
      unsigned long strut[12] = {0};
      XChangeProperty(display, window, strut_partial, XA_CARDINAL, 32,
                      PropModeReplace, (unsigned char *)strut, 12);
    }
  } else {
    Atom window_type_desktop =
        XInternAtom(display, "_NET_WM_WINDOW_TYPE_DESKTOP", False);
    if (window_type_desktop == None) {
      fprintf(stderr, "Failed to get _NET_WM_WINDOW_TYPE_DESKTOP atom\n");
      return false;
    }

    if (XChangeProperty(display, window, window_type, XA_ATOM, 32,
                        PropModeReplace, (unsigned char *)&window_type_desktop,
                        1) != Success) {
      fprintf(stderr, "Failed to set window type to desktop\n");
      return false;
    }
  }

  unsigned long opacity =
      (unsigned long)(0xFFFFFFFFul * WINDOW_OPACITY_DEFAULT);
  Atom window_opacity = XInternAtom(display, "_NET_WM_WINDOW_OPACITY", False);
  if (window_opacity != None) {
    XChangeProperty(display, window, window_opacity, XA_CARDINAL, 32,
                    PropModeReplace, (unsigned char *)&opacity, 1);
  }

  return true;
}

X11Details initX11(uint32_t location_x, uint32_t location_y, uint32_t size_x,
                   uint32_t size_y) {
  X11Details result = {.display = NULL, .window = 0};

  if (size_x == 0 || size_y == 0) {
    fprintf(stderr, "Invalid window size: %ux%u\n", size_x, size_y);
    return result;
  }

  char *xdg_current_desktop = getenv("XDG_CURRENT_DESKTOP");
  bool disable_redirect_override =
      is_supported_desktop_environment(xdg_current_desktop);

  Display *display = XOpenDisplay(NULL);
  if (display == NULL) {
    fprintf(stderr, "Cannot connect to X server\n");
    return result;
  }

  int screen = XDefaultScreen(display);
  Window root = DefaultRootWindow(display);

  XVisualInfo vinfo;
  if (!XMatchVisualInfo(display, screen, 32, TrueColor, &vinfo)) {
    fprintf(stderr, "No matching visual info found\n");
    XCloseDisplay(display);
    return result;
  }

  XSetWindowAttributes attrs;
  attrs.colormap = XCreateColormap(display, root, vinfo.visual, AllocNone);
  attrs.override_redirect = disable_redirect_override ? False : True;
  attrs.background_pixel = 0;
  attrs.border_pixel = 0;
  attrs.background_pixmap = None;

  unsigned long value_mask =
      CWColormap | CWBackPixel | CWBorderPixel | CWBackPixmap;
  if (!disable_redirect_override) {
    value_mask |= CWOverrideRedirect;
  }

  Window window =
      XCreateWindow(display, root, location_x, location_y, size_x, size_y, 0,
                    vinfo.depth, InputOutput, vinfo.visual, value_mask, &attrs);

  if (window == 0) {
    fprintf(stderr, "Failed to create window\n");
    XFreeColormap(display, attrs.colormap);
    XCloseDisplay(display);
    return result;
  }

  if (disable_redirect_override) {
    bool is_desktop_env = is_supported_desktop_environment(xdg_current_desktop);
    if (!setup_window_properties(display, window, is_desktop_env)) {
      fprintf(stderr, "Warning: Failed to set some window properties\n");
    }
  }

  XMapWindow(display, window);

  XSelectInput(display, window,
               ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

  XClassHint *xch = XAllocClassHint();
  if (xch != NULL) {
    xch->res_name = "connmap";
    xch->res_class = "connmap";
    XSetClassHint(display, window, xch);
    XFree(xch);
  }

  if (!disable_redirect_override) {
    XLowerWindow(display, window);
  }

  result.display = display;
  result.window = window;
  result.vinfo = vinfo;

  return result;
}

void cleanupX11(X11Details *x11) {
  if (!x11 || !x11->display) {
    return;
  }

  if (x11->window) {
    XDestroyWindow(x11->display, x11->window);
    x11->window = 0;
  }

  XCloseDisplay(x11->display);
  x11->display = NULL;
}