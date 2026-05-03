#pragma once
#include "Block.hpp"
#include <vector>
#include <glm/glm.hpp>

class Renderer;
class Camera;

class Chunk {
public:
    static const int SIZE = 16;
    Chunk(int x, int z);
    Block& getBlock(int x, int y, int z);
    void render(Renderer& renderer, const Camera& camera);

private:
    std::vector<std::vector<std::vector<Block>>> blocks;
    int chunkX, chunkZ;
};
