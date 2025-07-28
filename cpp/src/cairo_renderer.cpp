#include "cairo_renderer.hpp"

#include <cmath>
#include <iostream>

namespace connmap {

constexpr double PI = 3.14159265358979323846;

CairoRenderer::CairoRenderer(Display* display, Window window, Visual* visual,
                             int width, int height)
    : width(width), height(height) {
  surface = cairo_xlib_surface_create(display, window, visual, width, height);
  cairo_xlib_surface_set_size(surface, width, height);
}

CairoRenderer::~CairoRenderer() {
  if (surface) {
    cairo_surface_destroy(surface);
  }
}

void CairoRenderer::clear() {
  cairo_t* context = cairo_create(surface);
  cairo_set_source_rgba(context, 0, 0, 0, 0);
  cairo_set_operator(context, CAIRO_OPERATOR_SOURCE);
  cairo_paint(context);
  cairo_destroy(context);
  drawInvisiblePoint();
}

void CairoRenderer::drawWorld(const std::string& mapFilename) {
  cairo_t* context = cairo_create(surface);
  cairo_surface_t* world =
      cairo_image_surface_create_from_png(mapFilename.c_str());

  if (cairo_surface_status(world) != CAIRO_STATUS_SUCCESS) {
    std::cerr << "Failed to load map image: " << mapFilename << "\n";
    cairo_surface_destroy(world);
    cairo_destroy(context);
    return;
  }

  int original_width = cairo_image_surface_get_width(world);
  int original_height = cairo_image_surface_get_height(world);

  double scale_x = static_cast<double>(width) / original_width;
  double scale_y = static_cast<double>(height) / original_height;

  cairo_scale(context, scale_x, scale_y);
  cairo_set_source_surface(context, world, 0, 0);
  cairo_paint(context);
  cairo_surface_destroy(world);
  cairo_destroy(context);
  drawInvisiblePoint();
}

void CairoRenderer::drawPoint(double latitude, double longitude) {
  cairo_t* context = cairo_create(surface);
  cairo_set_source_rgba(context, 1, 0.2, 0.2, 0.8);
  cairo_set_line_width(context, 3.0);

  double scale_factor = static_cast<double>(width) / 1000.0;
  double dotRadius = (width <= 500) ? 4.0 : 8.0;

  double xOffset = -29.0 * scale_factor;
  double yOffset = 76.0 * scale_factor;

  double x = (longitude + 180) * (width / 360.0) + xOffset;
  double latRad = latitude * PI / 180;
  double mercN = log(tan((PI / 4) + (latRad / 2)));
  double y = (height / 2.0) - (width * mercN / (2 * PI)) + yOffset;

  cairo_arc(context, x, y, dotRadius, 0, 2 * PI);
  cairo_fill(context);
  cairo_destroy(context);
}

void CairoRenderer::flush() { cairo_surface_flush(surface); }

void CairoRenderer::drawInvisiblePoint() {
  cairo_t* context = cairo_create(surface);
  cairo_set_source_rgba(context, 0, 0, 0, 1);
  cairo_set_line_width(context, 1.0);
  cairo_arc(context, 0, 0, 1.0, 0, 2 * PI);
  cairo_fill(context);
  cairo_destroy(context);
}

}  // namespace connmap