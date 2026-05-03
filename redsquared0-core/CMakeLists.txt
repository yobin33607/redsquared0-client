add_library(Core World.cpp Player.cpp Block.cpp Chunk.cpp)
target_link_libraries(Core Engine)
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})