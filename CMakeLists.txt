project("luaui")
cmake_minimum_required(VERSION 2.8)

# lua

add_subdirectory("third_party/lua-5.2.3")

# sfml

set(SFML_ROOT_DIR "" CACHE PATH "")
if(NOT SFML_ROOT_DIR)
  message(FATAL_ERROR "SFML not found. Please set SFML_ROOT_DIR.")
endif()

add_subdirectory("${SFML_ROOT_DIR}" "sfml")
include_directories("${SFML_ROOT_DIR}/include")

# luaui

file(GLOB_RECURSE SRC_LUAUI "src/*.cpp" "src/*.h")
include_directories("src")

add_definitions("-DSFML_STATIC")
add_executable("luaui" WIN32 ${SRC_LUAUI})
target_link_libraries("luaui" "lua" "sfml-main" "sfml-system" "sfml-graphics")
