#pragma once
#include <string>

struct SDL_Window;

class Camera;

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool shouldClose() const;
    void processInput(Camera& camera);
    void swapBuffers();
    float getDeltaTime() const;
    int getWidth() const;
    int getHeight() const;
    SDL_Window* getNativeWindow() const;

    bool isForward() const;
    bool isBackward() const;
    bool isLeft() const;
    bool isRight() const;
    bool isUp() const;
    bool isDown() const;

private:
    int width, height;
    bool close;
    bool forward, backward, left, right, up, down;
    float deltaTime;
    unsigned int lastTicks;
    SDL_Window* window;
};
