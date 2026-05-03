#pragma once
#include "Chunk.hpp"
#include <unordered_map>

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

class Renderer;
class Camera;

class World {
public:
    World();
    ~World();
    void render(Renderer& renderer, const Camera& camera);
    Block& getBlock(int x, int y, int z);

private:
    std::unordered_map<std::pair<int, int>, Chunk*, hash_pair> chunks;
    Chunk* getChunk(int x, int z);
};
