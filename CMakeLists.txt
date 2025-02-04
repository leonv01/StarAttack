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
# -------------------------------------------------------------------------- #

# ---------------------------- Define lua import --------------------------- #
#add_subdirectory(extern/lua)
#target_include_directories(${PROJECT_NAME} PRIVATE lua_static)
# -------------------------------------------------------------------------- #


# -------------------------- Include source files -------------------------- #
include_directories(src)
# -------------------------------------------------------------------------- #

# ------------------------ Create executable target ------------------------ #
file(GLOB_RECURSE MAIN_SOURCE src/*.c)
add_executable(${PROJECT_NAME} ${MAIN_SOURCE})
# -------------------------------------------------------------------------- #

# -------------------- Copy resources to build directory ------------------- #
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources")
set(BUILD_DIR "${CMAKE_BINARY_DIR}/resources")

file(MAKE_DIRECTORY ${BUILD_DIR})

add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCE_DIR} ${BUILD_DIR}
)
# -------------------------------------------------------------------------- #

target_link_libraries(${PROJECT_NAME} PRIVATE raylib) #lua_static)


target_compile_definitions(${PROJECT_NAME} PRIVATE RAYLIB_STATIC)