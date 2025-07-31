#ifndef CAIRO_CONNMAP_H
#define CAIRO_CONNMAP_H

#include <cairo.h>
#include <cairo/cairo-xlib.h>
#include <stdbool.h>

void draw_world(cairo_surface_t *surface, char *mapName, int target_width,
                int target_height);
void draw_point(cairo_surface_t *surface, int map_width, double latitude,
                double longitude);
void clear_surface(cairo_surface_t *surface, bool under_wayland);

#endif
