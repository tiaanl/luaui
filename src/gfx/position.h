// luaui

#ifndef GFX_POSITION_H_
#define GFX_POSITION_H_

template <typename T>
struct Position {
  T x;
  T y;

  Position() : x(0), y(0) {}

  Position(T x, T y) : x(x), y(y) {}
};

typedef Position<int32_t> PositionI;

#endif  // GFX_POSITION_H_
