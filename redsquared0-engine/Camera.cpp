#include "Camera.hpp"

Camera::Camera() : x(0), y(10), z(0) {}

void Camera::setPosition(int px, int py, int pz) {
    x = px;
    y = py;
    z = pz;
}

int Camera::getX() const { return x; }
int Camera::getY() const { return y; }
int Camera::getZ() const { return z; }