#pragma once
#include <glm/glm.hpp>

class Camera;
class Window;

class Player {
public:
    Player();
    void update(Camera& camera, const Window& window);
    glm::vec3 getPosition() const;

private:
    glm::vec3 position;
    float speed;
};
