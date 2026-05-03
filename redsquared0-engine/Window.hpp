#pragma once
#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();
    bool shouldClose() const;
    void processInput();
    void swapBuffers();
    void clear();

private:
    int width, height;
    bool close;
};