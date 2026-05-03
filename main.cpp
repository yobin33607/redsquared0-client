#include "redsquared0-engine/Window.hpp"
#include "redsquared0-engine/Renderer.hpp"
#include "redsquared0-engine/Camera.hpp"
#include "redsquared0-core/World.hpp"
#include "redsquared0-core/Player.hpp"
#include <iostream>

Renderer* g_renderer;

int main() {
    try {
        Window window(80, 24, "Minecraft Clone");
        Renderer renderer;
        g_renderer = &renderer;
        Camera camera;
        World world;
        Player player;

        while (!window.shouldClose()) {
            window.clear();
            renderer.clear();
            world.render();
            renderer.display();
            window.processInput();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}