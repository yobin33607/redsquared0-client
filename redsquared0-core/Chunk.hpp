#pragma once
#include "Block.hpp"
#include <vector>
#include <glm/glm.hpp>

class Chunk {
public:
    static const int SIZE = 16;
    Chunk(int x, int z);
    Block& getBlock(int x, int y, int z);
    void render();

private:
    std::vector<std::vector<std::vector<Block>>> blocks;
    int chunkX, chunkZ;
};