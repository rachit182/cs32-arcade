# Crossy Roads README

Welcome to Crossy Roads! This game brings an exciting and fun experience as you guide chickens across various obstacles. Below, you will find instructions on how to compile and clean up the project, as well as an overview of the main file and library components.

## Compilation and Cleanup

### Compile the Game
To compile Crossy Roads, open your command line and type the following command: `make`

### Cleanup
If you need to clean up the compiled files, use `make clean` on the command line.

## Main File

### src/crossy_roads.cpp
This is the main file of the game. It integrates all the components and libraries to run Crossy Roads. It handles the game loop, event processing, and rendering.

### Game Controls:
The game is controlled using keyboard inputs. You can move the chicken using the `WASD` keys or the arrow keys (`UP`, `DOWN`, `LEFT`, `RIGHT`).

## Library Components

### src/lib/Car.hpp
- **Structure**: Defines the `Car` struct with position, direction, and size attributes, and a `Color` struct for car colors.
- **Function**: Uses OpenGL to render cars on the screen.

### src/lib/Chicken.hpp
- **Structure**: Defines the `Chicken` struct with position, size, and direction attributes.
- **Function**: Includes `drawChicken` to render the chicken using OpenGL.

### src/lib/Level.hpp
- Manages game levels with a mapping for different configurations.
- Integrates `Road` objects within each level.

### src/lib/Road.hpp
- **Class**: Defines the `Road` class with attributes like position, size, direction, velocity, and cars.
- Manages road segments and car movements on them.
