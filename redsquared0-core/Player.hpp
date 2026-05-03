#pragma once
#include <glm/glm.hpp>

class Player {
public:
    Player();
    void update();
    glm::vec3 getPosition() const;

private:
    glm::vec3 position;
};