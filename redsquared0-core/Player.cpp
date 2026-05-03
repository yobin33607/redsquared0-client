#include "Player.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>

Player::Player() : position(0.0f, 10.0f, 0.0f), speed(16.0f) {}

void Player::update(Camera& camera, const Window& window) {
    glm::vec3 moveDirection(0.0f);
    glm::vec3 forward = camera.getForward();
    glm::vec3 right = camera.getRight();
    forward.y = 0.0f;
    forward = glm::normalize(forward);

    if (window.isForward()) {
        moveDirection += forward;
    }
    if (window.isBackward()) {
        moveDirection -= forward;
    }
    if (window.isLeft()) {
        moveDirection -= right;
    }
    if (window.isRight()) {
        moveDirection += right;
    }
    if (window.isUp()) {
        moveDirection += glm::vec3(0.0f, 1.0f, 0.0f);
    }
    if (window.isDown()) {
        moveDirection -= glm::vec3(0.0f, 1.0f, 0.0f);
    }

    if (glm::length2(moveDirection) > 0.001f) {
        moveDirection = glm::normalize(moveDirection) * speed * window.getDeltaTime();
        camera.setPosition(camera.getPosition() + moveDirection);
    }

    position = camera.getPosition();
}

glm::vec3 Player::getPosition() const {
    return position;
}
