// luaui

#include "script/script.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

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

class Player {
public:
  static int l_Player_GetHealth(lua_State* state) {
    // Get the parameters.
    Player* player = *static_cast<Player**>(lua_touserdata(state, -1));

    // Return the health value.
    lua_pushnumber(state, player->GetHealth());
    return 1;
  }

  static int l_Player_SetHealth(lua_State* state) {
    // Get the parameters.
    Player* player = *static_cast<Player**>(lua_touserdata(state, -2));
    int32_t health = lua_tonumber(state, -1);

    // Set he new health.
    player->SetHealth(health);

    return 0;
  }

  // Create the metatable that represents this class in lua.
  static void RegisterClass(lua_State* state) {
    luaL_newmetatable(state, "Player");

    // Player.__index = Player
    lua_pushvalue(state, -1);
    lua_setfield(state, -2, "__index");

    // Player.get_health = function()
    lua_pushcfunction(state, l_Player_GetHealth);
    lua_setfield(state, -2, "GetHealth");

    // Player.set_health = function(health)
    lua_pushcfunction(state, l_Player_SetHealth);
    lua_setfield(state, -2, "SetHealth");
  }

  explicit Player(int32_t health) : m_health(health) {}
  ~Player();

  int32_t GetHealth() const { return m_health; }
  void SetHealth(int32_t health) { m_health = health; }

private:
  int32_t m_health;
};

std::map<std::string, Player*> g_players;

int l_get_player(lua_State* state) {
  // Get the name of the player.
  const char* paramName = luaL_checkstring(state, 1);

  // The Player we will return.
  Player* result = nullptr;

  // Get the player from the map.
  auto it = g_players.find(paramName);
  if (it == std::end(g_players)) {
    // The player doesn't exist, so create a new one.
    result = new Player(100);
    g_players.insert(std::make_pair(paramName, result));
  } else {
    result = it->second;
  }

  assert(result);

  Player** instance = (Player**)lua_newuserdata(state, sizeof(Player*));
  *instance = result;

  // Push the Player metatable onto the stack.
  luaL_getmetatable(state, "Player");

  // Set the player instance's metatable to Player.
  lua_setmetatable(state, -2);

  return 1;
}

Script::Script() {
  m_state = luaL_newstate();

  luaL_openlibs(m_state);

  // the_num = 100
  lua_pushnumber(m_state, 100);
  lua_setglobal(m_state, "the_num");

  lua_pushcfunction(m_state, l_get_player);
  lua_setglobal(m_state, "get_player");

  Player::RegisterClass(m_state);

  std::cout << "Running file" << std::endl;
  // Load the script file.
  luaL_dofile(m_state, "C:\\Workspace\\luaui\\scripts\\main.lua");
}

Script::~Script() {
  lua_close(m_state);
}
