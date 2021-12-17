cmake_minimum_required(VERSION 3.18)

project(
    SpaceGame
    VERSION 0.0
    LANGUAGES CXX
)

set(CMAKE_BUILD_TYPE debug CACHE STRING "Build mode <debug|release>")

add_subdirectory(src)
