# Red Squared

A modern GUI-based voxel adventure engine built in C++ with SDL2 and glm.

## Building

```bash
mkdir build
cd build
cmake ..
make
```

Run with `./RedSquared`

## Controls

- `WASD`: Move forward/back/strafe
- `Space`: Ascend
- `Shift`: Descend
- Mouse movement: Look around
- `Esc`: Quit

## Structure

- `redsquared0-engine`: GUI engine, window, renderer, camera controls
- `redsquared0-core`: World generation, voxel chunks, player movement
- `redsquared0-tools`: Development utilities

## Features

- Fully SDL2-driven graphical window
- First-person fly camera
- Procedural voxel terrain with stone, dirt, and grass
- Smooth perspective render of block clusters
- HUD and crosshair overlay
