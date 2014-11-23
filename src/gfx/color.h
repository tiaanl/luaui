// luaui

#ifndef GFX_COLOR_H_
#define GFX_COLOR_H_

#include <cstdint>

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;

  Color() : r(0), g(0), b(0), a(0) {}

  Color(int8_t r, int8_t g, int8_t b) : r(r), g(g), b(b), a(255) {}

  Color(int8_t r, int8_t g, int8_t b, int8_t a) : r(r), g(g), b(b), a(a) {}
};

#endif  // GFX_COLOR_H_
