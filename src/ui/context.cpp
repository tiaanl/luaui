// luaui

#include "ui/context.h"

const char* kTestScript =
    "print(\"123\")"
    "print(\"::\" .. mysin(10))";

static int l_sin(lua_State* state) {
  double d = lua_tonumber(state, 1);
  lua_pushnumber(state, sin(d));
  return 1;
}

Context::Context() : m_contextView(this), m_luaState(luaL_newstate()) {
  luaL_openlibs(m_luaState);
  luaL_loadstring(m_luaState, kTestScript);
  lua_pcall(m_luaState, 0, 0, 0);

  lua_pushcfunction(m_luaState, l_sin);
  lua_setglobal(m_luaState, "mysin");
}

Context::~Context() {
  lua_close(m_luaState);
}

void Context::Layout(const RectI& rect) {
  m_contextView.Layout(rect);
}

void Context::Render(sf::RenderTarget* target) {
  m_contextView.Render(target);
}
