#include "Player.hpp"

Player::Player() : position(0.0f, 10.0f, 0.0f) {}

void Player::update() {
    // Simple movement, for now static
}

glm::vec3 Player::getPosition() const {
    return position;
}