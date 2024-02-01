cmake_minimum_required(VERSION 3.0.0)
project(gpccgame)

find_package(SFML REQUIRED network audio graphics window system)

set(sourceDir "src")

add_executable(game ${sourceDir}/main.cpp ${sourceDir}/game.cpp)
target_link_libraries(game PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)