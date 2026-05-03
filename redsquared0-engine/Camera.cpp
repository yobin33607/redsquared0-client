#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() : position(0.0f, 12.0f, 0.0f), yaw(180.0f), pitch(-8.0f) {}

void Camera::setPosition(const glm::vec3& position) {
    this->position = position;
}

glm::vec3 Camera::getPosition() const {
    return position;
}

glm::vec3 Camera::getForward() const {
    const float radYaw = glm::radians(yaw);
    const float radPitch = glm::radians(pitch);
    glm::vec3 forward {
        std::cos(radPitch) * std::sin(radYaw),
        std::sin(radPitch),
        std::cos(radPitch) * std::cos(radYaw)
    };
    return glm::normalize(forward);
}

glm::vec3 Camera::getRight() const {
    return glm::normalize(glm::cross(getForward(), glm::vec3(0.0f, 1.0f, 0.0f)));
}

glm::vec3 Camera::getUp() const {
    return glm::normalize(glm::cross(getRight(), getForward()));
}

void Camera::rotate(float yawDelta, float pitchDelta) {
    yaw += yawDelta;
    pitch = glm::clamp(pitch + pitchDelta, -89.0f, 89.0f);
}
