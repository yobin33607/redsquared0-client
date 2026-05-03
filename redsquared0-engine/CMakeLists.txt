add_library(Engine Window.cpp Renderer.cpp Camera.cpp)
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Engine PUBLIC SDL2::SDL2)