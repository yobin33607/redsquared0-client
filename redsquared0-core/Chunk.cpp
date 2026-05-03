#include "Chunk.hpp"
#include "../redsquared0-engine/Renderer.hpp"
#include "../redsquared0-engine/Camera.hpp"
#include <cstdlib>

Chunk::Chunk(int x, int z) : chunkX(x), chunkZ(z) {
    blocks.resize(SIZE, std::vector<std::vector<Block>>(SIZE, std::vector<Block>(SIZE)));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int height = 6 + (std::rand() % 8);
            for (int k = 0; k < SIZE; ++k) {
                if (k < height - 2) {
                    blocks[i][j][k] = Block(STONE);
                } else if (k < height - 1) {
                    blocks[i][j][k] = Block(DIRT);
                } else if (k < height) {
                    blocks[i][j][k] = Block(GRASS);
                } else {
                    blocks[i][j][k] = Block(AIR);
                }
            }
        }
    }
}

Block& Chunk::getBlock(int x, int y, int z) {
    return blocks[x][y][z];
}

void Chunk::render(Renderer& renderer, const Camera& camera) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                if (blocks[i][j][k].getType() != AIR) {
                    const glm::vec3 color = blocks[i][j][k].getColor();
                    renderer.drawCube(chunkX * SIZE + i, k, chunkZ * SIZE + j, color, camera);
                }
            }
        }
    }
}
