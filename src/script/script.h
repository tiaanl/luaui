// luaui

#ifndef SCRIPT_SCRIPT_H_
#define SCRIPT_SCRIPT_H_

struct lua_State;

class Script {
public:
  Script();
  ~Script();

private:
  lua_State* m_state;
};

#endif  // SCRIPT_SCRIPT_H_
