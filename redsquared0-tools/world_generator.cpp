#include "../redsquared0-core/World.hpp"
#include <iostream>

int main() {
    World world;
    std::cout << "World generated with " << world.getBlock(0, 5, 0).getType() << std::endl;
    return 0;
}