project(pong)

include_directories(${KIRO_SOURCE_DIR}/src)
link_directories(${KIRO_BINARY_DIR}/src)

find_package(PkgConfig)
pkg_check_modules(SDL2 sdl2>=2 REQUIRED)

add_executable(pong main.cpp)
target_link_libraries(pong ${SDL2_LIBRARIES})
