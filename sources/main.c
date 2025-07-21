#include <X11/cursorfont.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cairo.h"
#include "config.h"
#include "ip.h"
#include "ss.h"
#include "x11.h"

int main(int argc, char **argv) {
  Config *config = readConfig();
  int size_x = config->map_width;
  int size_y = config->map_width / 2;
  char *mapName = malloc(15);
  if (config->black == true) {
    strcpy(mapName, "w1000b.png");
  } else {
    strcpy(mapName, "w1000.png");
  }

  char mapFilename[256];
  const char *home = getenv("HOME");
  if (!home) {
    fprintf(stderr, "HOME environment variable not set\n");
    return 1;
  }

  if (strlen(home) > 200) {
    fprintf(stderr,
            "HOME environment variable too long (max 200 characters)\n");
    return 1;
  }

  int ret = snprintf(mapFilename, sizeof(mapFilename), "%s%s%s", home,
                     RESOURCES, mapName);
  if (ret >= sizeof(mapFilename)) {
    fprintf(stderr, "Path too long: %s%s%s\n", home, RESOURCES, mapName);
    return 1;
  }

  initIPDatabase();
  X11Details x11 =
      initX11(config->location_x, config->location_y, size_x, size_y);
  cairo_surface_t *surface = cairo_xlib_surface_create(
      x11.display, x11.window, x11.vinfo.visual, size_x, size_y);
  cairo_xlib_surface_set_size(surface, size_x, size_y);

  XEvent event;
  int drag_start_x = 0, drag_start_y = 0;
  int window_start_x = 0, window_start_y = 0;
  int is_dragging = 0;

  Cursor normal_cursor = XCreateFontCursor(x11.display, XC_left_ptr);
  Cursor drag_cursor = XCreateFontCursor(x11.display, XC_fleur);

  XDefineCursor(x11.display, x11.window, normal_cursor);

  while (1) {
    clear_surface(surface);
    draw_world(surface, mapFilename, size_x, size_y);

    refreshConnections();

    char *ip;
    while ((ip = getConnection()) != NULL) {
      IPRange range = getCoordinates(ip);
      if (range.start == 0) continue;
      draw_point(surface, size_x, range.latitude, range.longitude);
    }

    cairo_surface_flush(surface);

    while (XPending(x11.display)) {
      XNextEvent(x11.display, &event);

      switch (event.type) {
        case ButtonPress:
          if (event.xbutton.button == Button1) {
            is_dragging = 1;
            drag_start_x = event.xbutton.x_root;
            drag_start_y = event.xbutton.y_root;

            Window child;
            XTranslateCoordinates(x11.display, x11.window,
                                  DefaultRootWindow(x11.display), 0, 0,
                                  &window_start_x, &window_start_y, &child);

            XDefineCursor(x11.display, x11.window, drag_cursor);
          }
          break;

        case ButtonRelease:
          if (event.xbutton.button == Button1) {
            is_dragging = 0;

            XDefineCursor(x11.display, x11.window, normal_cursor);
          }
          break;

        case MotionNotify:
          if (is_dragging) {
            int delta_x = event.xmotion.x_root - drag_start_x;
            int delta_y = event.xmotion.y_root - drag_start_y;

            XMoveWindow(x11.display, x11.window, window_start_x + delta_x,
                        window_start_y + delta_y);
          }
          break;
      }
    }

    if (!is_dragging) {
      sleep(config->update_interval);
    } else {
      usleep(10000);
    }
  }

  Display *display = cairo_xlib_surface_get_display(surface);
  cairo_surface_destroy(surface);

  XFreeCursor(x11.display, normal_cursor);
  XFreeCursor(x11.display, drag_cursor);

  XCloseDisplay(display);
  return 0;
}
