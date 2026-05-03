#pragma once
#include <vector>
#include <string>

class Renderer {
public:
    Renderer();
    ~Renderer();
    void clear();
    void drawCube(int x, int y, int z, char type);
    void display();

private:
    std::vector<std::string> screen;
    int width, height;
};