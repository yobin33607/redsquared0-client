#include "Window.hpp"
#include "Camera.hpp"
#include <SDL2/SDL.h>
#include <stdexcept>

Window::Window(int w, int h, const std::string& title)
    : width(w), height(h), close(false), forward(false), backward(false), left(false), right(false), up(false), down(false), deltaTime(0.0f), lastTicks(SDL_GetTicks()), window(nullptr) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) != 0) {
        throw std::runtime_error(SDL_GetError());
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        throw std::runtime_error(SDL_GetError());
    }

    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_ShowCursor(SDL_DISABLE);
}

Window::~Window() {
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

bool Window::shouldClose() const {
    return close;
}

void Window::processInput(Camera& camera) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            close = true;
        } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
            close = true;
        } else if (event.type == SDL_MOUSEMOTION) {
            camera.rotate(event.motion.xrel * 0.12f, event.motion.yrel * 0.12f);
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    forward = state[SDL_SCANCODE_W];
    backward = state[SDL_SCANCODE_S];
    left = state[SDL_SCANCODE_A];
    right = state[SDL_SCANCODE_D];
    up = state[SDL_SCANCODE_SPACE];
    down = state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT];

    if (state[SDL_SCANCODE_ESCAPE]) {
        close = true;
    }

    unsigned int current = SDL_GetTicks();
    deltaTime = static_cast<float>(current - lastTicks) / 1000.0f;
    if (deltaTime <= 0.0f) {
        deltaTime = 0.001f;
    }
    lastTicks = current;
}

void Window::swapBuffers() {
    // SDL_RenderPresent is handled by Renderer, so this is intentionally empty.
}

float Window::getDeltaTime() const {
    return deltaTime;
}

int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}

SDL_Window* Window::getNativeWindow() const {
    return window;
}

bool Window::isForward() const {
    return forward;
}

bool Window::isBackward() const {
    return backward;
}

bool Window::isLeft() const {
    return left;
}

bool Window::isRight() const {
    return right;
}

bool Window::isUp() const {
    return up;
}

bool Window::isDown() const {
    return down;
}
