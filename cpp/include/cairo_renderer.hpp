#ifndef CAIRO_RENDERER_HPP
#define CAIRO_RENDERER_HPP

#include <cairo/cairo-xlib.h>
#include <cairo/cairo.h>

#include <memory>
#include <string>

namespace connmap {

class CairoRenderer {
 public:
  CairoRenderer(Display* display, Window window, Visual* visual, int width,
                int height);
  ~CairoRenderer();

  void clear();
  void drawWorld(const std::string& mapFilename);
  void drawPoint(double latitude, double longitude);
  void flush();

 private:
  void drawInvisiblePoint();

  cairo_surface_t* surface = nullptr;
  int width;
  int height;
};

}  // namespace connmap

#endif  // CAIRO_RENDERER_HPP