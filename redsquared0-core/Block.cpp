#include "Block.hpp"

Block::Block(BlockType t) : type(t) {}

BlockType Block::getType() const {
    return type;
}

glm::vec3 Block::getColor() const {
    switch (type) {
        case GRASS: return glm::vec3(0.0f, 1.0f, 0.0f);
        case DIRT: return glm::vec3(0.5f, 0.25f, 0.0f);
        case STONE: return glm::vec3(0.5f, 0.5f, 0.5f);
        default: return glm::vec3(0.0f, 0.0f, 0.0f);
    }
}