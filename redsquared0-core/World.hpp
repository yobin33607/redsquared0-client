#pragma once
#include "Chunk.hpp"
#include <vector>
#include <unordered_map>

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;  // or some other combination
    }
};

class World {
public:
    World();
    void render();
    Block& getBlock(int x, int y, int z);

private:
    std::unordered_map<std::pair<int, int>, Chunk*, hash_pair> chunks;
    Chunk* getChunk(int x, int z);
};