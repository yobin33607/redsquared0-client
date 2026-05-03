#pragma once

class Camera {
public:
    Camera();
    void setPosition(int x, int y, int z);
    int getX() const;
    int getY() const;
    int getZ() const;

private:
    int x, y, z;
};