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
  strcat(strcpy(mapFilename, getenv("HOME")), RESOURCES);
  strcat(mapFilename, mapName);

  initIPDatabase();
  X11Details x11 =
      initX11(config->location_x, config->location_y, size_x, size_y);
  cairo_surface_t *surface = cairo_xlib_surface_create(
      x11.display, x11.window, x11.vinfo.visual, size_x, size_y);
  cairo_xlib_surface_set_size(surface, size_x, size_y);

  XEvent event;

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
    }

    sleep(config->update_interval);
  }

  Display *display = cairo_xlib_surface_get_display(surface);
  cairo_surface_destroy(surface);
  XCloseDisplay(display);
  return 0;
}
