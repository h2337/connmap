#ifndef X11_WINDOW_HPP
#define X11_WINDOW_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <cstdint>
#include <memory>

namespace connmap {

class X11Window {
 public:
  X11Window(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
  ~X11Window();

  bool init();
  void processEvents();
  bool isDragging() const { return is_dragging; }

  Display* getDisplay() const { return display; }
  Window getWindow() const { return window; }
  XVisualInfo getVisualInfo() const { return vinfo; }

  void setNormalCursor();
  void setDragCursor();

 private:
  void setupWindowProperties();
  void setupWindowPropertiesForDE();
  void setupWindowPropertiesForWM();
  bool isDesktopEnvironment() const;
  std::string getDesktopEnvironment() const;

  uint32_t location_x;
  uint32_t location_y;
  uint32_t size_x;
  uint32_t size_y;

  Display* display = nullptr;
  Window window = 0;
  XVisualInfo vinfo;
  Cursor normal_cursor = 0;
  Cursor drag_cursor = 0;

  bool is_dragging = false;
  int drag_start_x = 0;
  int drag_start_y = 0;
  int window_start_x = 0;
  int window_start_y = 0;
};

}  // namespace connmap

#endif  // X11_WINDOW_HPP