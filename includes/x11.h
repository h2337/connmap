#ifndef X11_H
#define X11_H

#include <X11/Xlib.h>
#include <X11/extensions/shape.h>
#include <stdint.h>

typedef struct X11Details {
  Display *display;
  Window window;
  XVisualInfo vinfo;
} X11Details;

X11Details initX11(uint32_t location_x, uint32_t location_y, uint32_t size_x,
                   uint32_t size_y);
void cleanupX11(X11Details *x11);

#endif
