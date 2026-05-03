cmake_minimum_required(VERSION 3.10)
project(RedSquaredGame)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-DSDL_MAIN_HANDLED)

find_package(SDL2 REQUIRED)

# Add subdirectories
add_subdirectory(redsquared0-engine)
add_subdirectory(redsquared0-core)
add_subdirectory(redsquared0-tools)

# Main executable
add_executable(RedSquared main.cpp)
target_link_libraries(RedSquared Engine Core)