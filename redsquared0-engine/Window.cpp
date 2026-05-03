#include "Window.hpp"
#include <iostream>

Window::Window(int w, int h, const std::string& title) : width(w), height(h), close(false) {
    std::cout << "Window created: " << title << " " << width << "x" << height << std::endl;
}

Window::~Window() {
    std::cout << "Window destroyed" << std::endl;
}

bool Window::shouldClose() const {
    return close;
}

void Window::processInput() {
    char input;
    std::cout << "Press 'q' to quit, any other key to continue: ";
    std::cin >> input;
    if (input == 'q') close = true;
}

void Window::swapBuffers() {
    // No op for console
}

void Window::clear() {
    std::cout << "\033[2J\033[1;1H"; // Clear screen
}