// luaui

#ifndef GFX_RECT_H_
#define GFX_RECT_H_

#include "gfx/position.h"
#include "gfx/size.h"

template <typename T>
struct Rect {
  Position<T> pos;
  Size<T> size;

  Rect() {}

  Rect(T x, T y, T width, T height) : pos(x, y), size(width, height) {}

  Rect(const Position<T>& pos, const Size<T>& size) : pos(pos), size(size) {}
};

#endif  // GFX_RECT_H_
