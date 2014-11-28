// luaui

#ifndef SCRIPT_SCRIPT_H_
#define SCRIPT_SCRIPT_H_

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class Context;

class Script {
public:
  Script();
  ~Script();

  lua_State* GetState() const { return m_state; }

  bool Init(Context* context);

  // Run the Context.Start and Context.Stop callbacks.
  void RunUiStart();
  void RunUiStop();

private:
  lua_State* m_state;
};

#endif  // SCRIPT_SCRIPT_H_
