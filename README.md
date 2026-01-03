# cub3D - A 3D Graphics Engine

A first-person 3D graphics renderer built from scratch, translating mathematical principles of perspective rendering into real-time interactive visualization.

## Overview

cub3D is a 3D maze explorer that demonstrates how mathematical concepts become tangible in programming. The project bridges the gap between abstract geometric theory and practical graphics implementation, rendering a navigable 3D world through a 2D screen.

## Core Concepts

### Ray Casting
The foundation of this project is **ray casting**, a technique that simulates how light rays interact with a scene. Instead of tracing light bouncing around the environment (which is computationally expensive), we reverse the process: for each pixel on the screen, we cast an imaginary ray into the 3D world and calculate what it intersects with.

This elegant mathematical approach—converting a 2D screen coordinate into a 3D ray direction—allows us to render complex 3D scenes with minimal computational overhead, making it perfect for real-time graphics on limited hardware.

### DDA Algorithm (Digital Differential Analyzer)
The map is represented as a 2D grid, where each cell is either a wall or empty space. When casting a ray, we need to check every grid cell it passes through. If we took too large a step and "jumped over" a cell, we'd miss walls entirely.

The **DDA algorithm** solves this elegantly: it steps along the ray in precise increments, ensuring we never skip a grid cell. At each step, we check if the current grid cell contains a wall. This guarantees we'll catch the first wall the ray hits, no matter how close it is to the ray's path.

### Perspective Transformation
The renderer converts player position and view angle into ray directions using trigonometric functions. Mouse input updates the view angle in real-time, and the mathematics automatically handles how the 3D world transforms on screen based on camera orientation.

## Features

- **Real-time Navigation**: Move through the maze with smooth, responsive controls
- **Mouse-Controlled Camera**: Look around by moving the mouse—intuitive 3D camera control
- **Minimap**: Bird's-eye view of the environment showing player position and orientation
- **Wall Rendering**: Textured walls with proper depth perception

## Map Parsing & Validation

Before rendering can begin, the map file must be parsed and validated. This ensures the game world is properly defined and prevents crashes or undefined behavior during runtime.

The validation process checks for:
- **Proper map structure**: The map must be enclosed by walls to prevent rays from escaping into undefined space
- **Required elements**: Player starting position and orientation must be present
- **Valid characters**: Only recognized symbols (walls, empty space, player position, etc.) are allowed
- **Consistent dimensions**: The map data is stored in a way that supports efficient ray-wall intersection queries
- **Configuration parsing**: Texture paths and color values are loaded and verified before use

This demonstrates an important programming principle: **robust input validation prevents cascading bugs**. By thoroughly checking the map at startup, the renderer can safely assume valid data during the performance-critical rendering loop.

## Technical Implementation

The project uses **minilibX**, to handle pixel rendering. All 3D mathematics is implemented from scratch without relying on graphics libraries' built-in transformations.

The rendering pipeline works as follows:
1. For each column of pixels, cast a ray from the camera through that column
2. Trace the ray until it hits a wall
3. Calculate the distance to the wall and determine its color/texture
4. Draw the column with appropriate shading based on distance
5. Render the minimap showing the scene from above

## Learning Outcome

This project teaches the essential skill of **translating mathematics into code**. Complex geometric operations become manageable when broken down into iterative, step-by-step algorithms.

## Building & Running

```bash
make
./cub3D [map_file]
```

Use WASD to move, mouse to look around, and ESC to exit.

---

*A 42 School project showcasing graphics programming fundamentals.*
