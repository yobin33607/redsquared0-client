#include "Renderer.hpp"
#include <iostream>
#include <algorithm>

Renderer::Renderer() : width(80), height(24) {
    screen.resize(height, std::string(width, ' '));
}

Renderer::~Renderer() {}

void Renderer::clear() {
    for (auto& line : screen) {
        std::fill(line.begin(), line.end(), ' ');
    }
}

void Renderer::drawCube(int x, int y, int z, char type) {
    // Simple 2D projection, ignore z for now
    if (x >= 0 && x < width && y >= 0 && y < height) {
        screen[height - 1 - y][x] = type; // Flip y
    }
}

void Renderer::display() {
    std::cout << "\033[2J\033[1;1H"; // Clear screen
    for (const auto& line : screen) {
        std::cout << line << std::endl;
    }
}