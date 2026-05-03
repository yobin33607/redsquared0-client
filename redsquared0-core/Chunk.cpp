#include "Chunk.hpp"
#include "../redsquared0-engine/Renderer.hpp"
#include <cstdlib>

extern Renderer* g_renderer;

Chunk::Chunk(int x, int z) : chunkX(x), chunkZ(z) {
    blocks.resize(SIZE, std::vector<std::vector<Block>>(SIZE, std::vector<Block>(SIZE)));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                int height = rand() % 10 + 5;
                if (k < height) {
                    blocks[i][j][k] = Block(STONE);
                } else if (k == height) {
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

void Chunk::render() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                if (blocks[i][j][k].getType() != AIR) {
                    char type = blocks[i][j][k].getType() == GRASS ? 'G' : 'S';
                    g_renderer->drawCube(chunkX * SIZE + i, k, chunkZ * SIZE + j, type);
                }
            }
        }
    }
}