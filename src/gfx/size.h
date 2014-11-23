// luaui

#ifndef GFX_SIZE_H_
#define GFX_SIZE_H_

template <typename T>
struct Size {
  T width;
  T height;

  Size() : width(0), height(0) {}

  Size(T width, T height) : width(width), height(height) {}
};

#endif  // GFX_SIZE_H_
