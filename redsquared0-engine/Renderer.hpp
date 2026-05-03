#pragma once
#include <glm/glm.hpp>

struct SDL_Window;
struct SDL_Renderer;
class Camera;

class Renderer {
public:
    Renderer(SDL_Window* window, int width, int height);
    ~Renderer();

    void clear();
    void drawCube(float x, float y, float z, const glm::vec3& color, const Camera& camera);
    void display(float deltaTime);

private:
    SDL_Renderer* renderer;
    int width, height;
    int fps;
    float fpsTimer;
    int frameCount;
};
