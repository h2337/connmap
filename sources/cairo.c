#include "cairo.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265

void draw_invisible_point(cairo_surface_t *surface) {
  cairo_t *context = cairo_create(surface);
  cairo_set_source_rgba(context, 0, 0, 0, 1);
  cairo_set_line_width(context, 1.0);
  cairo_arc(context, 0, 0, 1.0, 0, 2 * 3.14);
  cairo_fill(context);
  cairo_destroy(context);
}

void draw_world(cairo_surface_t *surface, char *mapFilename, int target_width,
                int target_height) {
  cairo_t *context = cairo_create(surface);
  cairo_surface_t *world = cairo_image_surface_create_from_png(mapFilename);

  int original_width = cairo_image_surface_get_width(world);
  int original_height = cairo_image_surface_get_height(world);

  double scale_x = (double)target_width / original_width;
  double scale_y = (double)target_height / original_height;

  cairo_scale(context, scale_x, scale_y);
  cairo_set_source_surface(context, world, 0, 0);
  cairo_paint(context);
  cairo_surface_destroy(world);
  cairo_destroy(context);
  draw_invisible_point(surface);
}

void draw_point(cairo_surface_t *surface, int map_width, double latitude,
                double longitude) {
  cairo_t *context = cairo_create(surface);
  cairo_set_source_rgba(context, 1, 0.2, 0.2, 0.8);
  cairo_set_line_width(context, 3.0);

  double scale_factor = (double)map_width / 1000.0;
  double dotRadius = (map_width <= 500) ? 4.0 : 8.0;
  double width = map_width;
  double height = map_width / 2;

  double xOffset = -29.0 * scale_factor;
  double yOffset = 76.0 * scale_factor;

  double x = (longitude + 180) * (width / 360) + xOffset;
  double latRad = latitude * PI / 180;
  double mercN = log(tan((PI / 4) + (latRad / 2)));
  double y = (height / 2) - (width * mercN / (2 * PI)) + yOffset;

  cairo_arc(context, x, y, dotRadius, 0, 2 * PI);
  cairo_fill(context);
  cairo_destroy(context);
}

void clear_surface(cairo_surface_t *surface) {
  cairo_t *context = cairo_create(surface);
  cairo_set_source_rgba(context, 0, 0, 0, 0);
  cairo_set_operator(context, CAIRO_OPERATOR_SOURCE);
  cairo_paint(context);
  cairo_destroy(context);
  draw_invisible_point(surface);
}
