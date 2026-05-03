#pragma once
#include <glm/glm.hpp>

enum BlockType { AIR, GRASS, DIRT, STONE };

class Block {
public:
    Block(BlockType type = AIR);
    BlockType getType() const;
    glm::vec3 getColor() const;

private:
    BlockType type;
};