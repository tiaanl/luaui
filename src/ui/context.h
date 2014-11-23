// luaui

#ifndef UI_CONTEXT_H_
#define UI_CONTEXT_H_

#include <cstdint>

#include "gfx/size.h"
#include "ui/context_view.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class Context {
public:
  Context();
  ~Context();

  void Layout(const RectI& size);
  void Render(sf::RenderTarget* target);

protected:
  ContextView m_contextView;

  lua_State* m_luaState;
};

#endif  // UI_CONTEXT_H_
