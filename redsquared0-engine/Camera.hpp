#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    Camera();
    void setPosition(const glm::vec3& position);
    glm::vec3 getPosition() const;

    glm::vec3 getForward() const;
    glm::vec3 getRight() const;
    glm::vec3 getUp() const;

    void rotate(float yawDelta, float pitchDelta);

private:
    glm::vec3 position;
    float yaw;
    float pitch;
};
