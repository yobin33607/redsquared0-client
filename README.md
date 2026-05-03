# Minecraft Clone

A simple console-based Minecraft-like game built in C++.

## Building

```
mkdir build
cd build
cmake ..
make
```

Run with `./MinecraftClone`

## Structure

- redsquared0-engine: Game engine (console window, text renderer, camera)
- redsquared0-core: Core game logic (world, blocks, player)
- redsquared0-tools: Tools for development (world generator - currently broken due to global renderer)

## Running

The game displays a 2D top-down view of the generated world.
Press 'q' to quit.