// luaui

#include "script/script.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>

#include "ui/context.h"

namespace {

static const char* kUILibName = "ui";

static int StackDump(lua_State* state) {
  std::cout << "--[[" << std::endl;

  int top = lua_gettop(state);  // Depth of the stack.

  for (int i = 0; i <= top; ++i) {
    std::cout << "  " << i << ": ";
    int t = lua_type(state, i);
    switch (t) {
      case LUA_TSTRING:
        std::cout << lua_tostring(state, i);
        break;

      case LUA_TBOOLEAN:
        std::cout << std::boolalpha << (lua_toboolean(state, i) > 0);
        break;

      case LUA_TNUMBER:
        std::cout << lua_tonumber(state, i);
        break;

      default:
        std::cout << lua_typename(state, t);
        break;
    }

    std::cout << std::endl;
  }

  std::cout << "]]--" << std::endl;

  // We're not returning anything.
  return 0;
}

static int l_getView(lua_State* L) {
  // Read parameters.
  const char* viewName = lua_tostring(L, -1);

  // Get the context pointer from the globals.
  lua_getglobal(L, "context");
  assert(lua_isuserdata(L, -1));
  Context* context = static_cast<Context*>(lua_touserdata(L, -1));

  View* view = context->FindView(viewName);

  if (view) {
    view->PushInstance(L);
  } else {
    lua_pushnil(L);
  }

  return 1;
}

static int l_View_getName(lua_State* L) {
  // Get the View object.
  View* view = static_cast<View*>(lua_touserdata(L, -1));

  // Push the name onto the stack.
  lua_pushstring(L, view->GetName().data());
  return 1;
}

static const luaL_Reg kViewFunctions[] = {
  {"getName", l_View_getName},
  {0, 0},
};

static void RegisterViewMetaTable(lua_State* L) {
  luaL_newmetatable(L, "View");

  // View.__index = View
  //lua_pushvalue(L, -1);
  //lua_setfield(L, -2, "__index");

  //luaL_setfuncs(L, kViewFunctions, 0);
}

static int OpenLib_ui(lua_State* L) {
  // Make sure the global ui table exists.
  lua_getglobal(L, kUILibName);
  if (!lua_istable(L, -1)) {
    lua_pop(L, 1);
    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, kUILibName);
  }

  // Register the getView function.
  lua_pushcfunction(L, l_getView);
  lua_setfield(L, -2, "getView");

  StackDump(L);

  // Push the View metatable.
  RegisterViewMetaTable(L);

  StackDump(L);

  return 1;
}

}  // namespace

Script::Script() : m_state(nullptr) {
}

Script::~Script() {
  if (m_state)
    lua_close(m_state);
}

bool Script::Init(Context* context) {
  // Create the VM.
  m_state = luaL_newstate();

  // Load the standard libs.
  luaL_openlibs(m_state);

  // Set a pointer to the context as a global.
  lua_pushlightuserdata(m_state, context);
  lua_setglobal(m_state, "context");

  // Require the ui library so that we can just start to use it.
  luaL_requiref(m_state, "ui", OpenLib_ui, 1);

  // Load the script file.
  luaL_dofile(m_state, "C:\\Workspace\\luaui\\scripts\\main.lua");
  const char* error = lua_tostring(m_state, -1);
  if (error)
    std::cout << error << std::endl;

  return true;
}

void Script::RunUiStart() {
  lua_getglobal(m_state, "ui");
  lua_getfield(m_state, -1, "start");
  if (lua_isfunction(m_state, -1))
    lua_pcall(m_state, 0, 0, 0);
}

void Script::RunUiStop() {
  lua_getglobal(m_state, "ui");
  lua_getfield(m_state, -1, "stop");
  if (lua_isfunction(m_state, -1))
    lua_pcall(m_state, 0, 0, 0);
}
