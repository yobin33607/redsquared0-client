#include "redsquared0-engine/Window.hpp"
#include "redsquared0-engine/Renderer.hpp"
#include "redsquared0-engine/Camera.hpp"
#include "redsquared0-core/World.hpp"
#include "redsquared0-core/Player.hpp"
#include <glm/glm.hpp>
#include <iostream>
#include <ctime>

int main() {
    try {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        Window window(1280, 720, "Red Squared");
        Renderer renderer(window.getNativeWindow(), window.getWidth(), window.getHeight());

        Camera camera;
        camera.setPosition(glm::vec3(0.0f, 18.0f, 40.0f));

        Player player;
        World world;

        while (!window.shouldClose()) {
            window.processInput(camera);
            player.update(camera, window);

            renderer.clear();
            world.render(renderer, camera);
            renderer.display(window.getDeltaTime());
            window.swapBuffers();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
