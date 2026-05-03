cmake_minimum_required(VERSION 3.10)
project(MinecraftClone)

set(CMAKE_CXX_STANDARD 17)

# No external dependencies for console version

# Add subdirectories
add_subdirectory(redsquared0-engine)
add_subdirectory(redsquared0-core)
add_subdirectory(redsquared0-tools)

# Main executable
add_executable(MinecraftClone main.cpp)
target_link_libraries(MinecraftClone Engine Core)