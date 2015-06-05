cmake_minimum_required(VERSION 2.6)
project(KIRO C)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

set(TARNAME "pong")
set(PONG_VERSION_MAJOR "0")
set(PONG_VERSION_MINOR "1")
set(PONG_VERSION_RELEASE "1")
set(PONG_VERSION_STRING
"${PONG_VERSION_MAJOR}.${PONG_VERSION_MINOR}.${PONG_VERSION_PATCH}")
set(VERSION "${PONG_VERSION_STRING}")
set(PONG_DESCRIPTION "YAY PONG!!")

#Not yet needed
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/common/cmake")

find_package(PkgConfig)
find_program(LIBSDL2 sdl2 REQUIRED)
include_directories(
        SYSTEM
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${LIBSDL2_DIR})

set(PONG_DEPS ${LIBSDL2_LIBRARIES})

set(PONG_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-Wall -Wextra -std=c++11)

#add_subdirectory(src)
add_subdirectory(bin)
