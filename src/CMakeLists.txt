configure_file(SpaceGame.hpp.in SpaceGame.hpp)
add_executable(SpaceGame
    SpaceGame.cpp
    SolarSystem.cpp
)

set(CMAKE_BUILD_TYPE "debug" CACHE STRING "Build mode <debug|release>")
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ Language Standard")
set(CMAKE_CXX_EXTENSIONS OFF)
set(POSITION_INDEPENDENT_CODE OFF)

find_package(SFML 2.5 COMPONENTS graphics system window REQUIRED)

target_link_directories(SpaceGame
    ../sfml
)

target_link_libraries(SpaceGame
    sfml-graphics
    sfml-system
    sfml-window
)
