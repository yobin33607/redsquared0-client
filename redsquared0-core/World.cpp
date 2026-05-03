#include "World.hpp"

World::World() {
    // Generate a few chunks
    for (int x = -2; x <= 2; ++x) {
        for (int z = -2; z <= 2; ++z) {
            chunks[{x, z}] = new Chunk(x, z);
        }
    }
}

void World::render() {
    for (auto& pair : chunks) {
        pair.second->render();
    }
}

Block& World::getBlock(int x, int y, int z) {
    int chunkX = x / Chunk::SIZE;
    int chunkZ = z / Chunk::SIZE;
    int localX = x % Chunk::SIZE;
    int localZ = z % Chunk::SIZE;
    return getChunk(chunkX, chunkZ)->getBlock(localX, y, localZ);
}

Chunk* World::getChunk(int x, int z) {
    auto key = std::make_pair(x, z);
    if (chunks.find(key) == chunks.end()) {
        chunks[key] = new Chunk(x, z);
    }
    return chunks[key];
}