// luaui

#ifndef GFX_SIZE_H_
#define GFX_SIZE_H_

template <typename T>
struct Size {
  T width;
  T height;

  Size() : width(0), height(0) {}

  Size(T width, T height) : width(width), height(height) {}

  void GrowTo(const Size& size) {
    width = std::max(width, size.width);
    height = std::max(height, size.height);
  }
};

typedef Size<int32_t> SizeI;

#endif  // GFX_SIZE_H_
