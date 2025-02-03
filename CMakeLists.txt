cmake_minimum_required(VERSION 3.20)
# Set project name and lanugage
project(StarAttack C)

# Set project language standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# -------------------------- Define raylib import -------------------------- #
add_subdirectory(extern/raylib)
set(RAYLIB_STATIC ON)
set(RAYLIB_SOURCE_PATH extern/raygui/src)

include_directories(src)

file(GLOB_RECURSE MAIN_SOURCE src/*.c)

add_executable(${PROJECT_NAME} ${MAIN_SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_compile_definitions(${PROJECT_NAME} PRIVATE RAYLIB_STATIC)