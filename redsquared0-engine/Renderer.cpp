#include "Renderer.hpp"
#include "Camera.hpp"
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <algorithm>
#include <stdexcept>

Renderer::Renderer(SDL_Window* window, int w, int h)
    : renderer(nullptr), width(w), height(h), fps(0), fpsTimer(0.0f), frameCount(0) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        throw std::runtime_error(SDL_GetError());
    }
}

Renderer::~Renderer() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 14, 18, 38, 255);
    SDL_RenderClear(renderer);
}

void Renderer::drawCube(float x, float y, float z, const glm::vec3& color, const Camera& camera) {
    glm::vec3 worldPosition(x, y, z);
    glm::vec3 relative = worldPosition - camera.getPosition();
    float depth = glm::dot(relative, camera.getForward());
    if (depth <= 0.6f) {
        return;
    }

    glm::vec3 right = camera.getRight();
    glm::vec3 up = camera.getUp();
    float projectedX = glm::dot(relative, right) / depth;
    float projectedY = glm::dot(relative, up) / depth;

    float screenX = width * 0.5f + projectedX * width * 0.45f;
    float screenY = height * 0.5f - projectedY * height * 0.45f;
    float size = std::clamp(90.0f / depth, 6.0f, 120.0f);

    SDL_Rect rect{
        static_cast<int>(screenX - size * 0.5f),
        static_cast<int>(screenY - size * 0.5f),
        static_cast<int>(size),
        static_cast<int>(size)
    };

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer,
                           static_cast<uint8_t>(glm::clamp(color.r, 0.0f, 1.0f) * 255.0f),
                           static_cast<uint8_t>(glm::clamp(color.g, 0.0f, 1.0f) * 255.0f),
                           static_cast<uint8_t>(glm::clamp(color.b, 0.0f, 1.0f) * 255.0f),
                           255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 160);
    SDL_RenderDrawRect(renderer, &rect);
}

void Renderer::display(float deltaTime) {
    frameCount++;
    fpsTimer += deltaTime;
    if (fpsTimer >= 1.0f) {
        fps = frameCount;
        frameCount = 0;
        fpsTimer -= 1.0f;
    }

    int centerX = width / 2;
    int centerY = height / 2;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 190);
    SDL_RenderDrawLine(renderer, centerX - 12, centerY, centerX + 12, centerY);
    SDL_RenderDrawLine(renderer, centerX, centerY - 12, centerX, centerY + 12);

    SDL_Rect hudBackground = {18, 18, 260, 110};
    SDL_SetRenderDrawColor(renderer, 8, 12, 24, 200);
    SDL_RenderFillRect(renderer, &hudBackground);
    SDL_SetRenderDrawColor(renderer, 70, 90, 150, 110);
    SDL_RenderDrawRect(renderer, &hudBackground);

    SDL_RenderPresent(renderer);
}
