# Crossy Roads README

Welcome to Crossy Roads! This game brings an exciting and fun experience as you guide chickens across various obstacles. Below, you will find instructions on how to compile and clean up the project, as well as an overview of the main file and library components.

## Compilation and Cleanup

### Compile the Game
To compile Crossy Roads, open your command line and type the following command: 'make'

### Cleanup
If you need to clean up the compiled files, use 'make clean' on the command line.

## Main File

### [src/crossy_roads.cpp]
This is the main file of the game. It integrates all the components and libraries to run Crossy Roads. It handles the game loop, event processing, and rendering.

### Game Controls:
The game is controlled using keyboard inputs. You can move the chicken using the `WASD` keys or the arrow keys (`UP`, `DOWN`, `LEFT`, `RIGHT`).


## Library

### [src/lib/...]

#### Chicken.hpp
Chicken is the main player in our game and `Chicken.hpp` contains code to define the `Chicken` structure and the `drawChicken` function. 
This file is an essential component of the Crossy Roads game.

- **Structure:** The `Chicken` struct includes properties for position (`x`, `y`) and size of the chicken. The position is updated in the main loop.
- **Function:** The `drawChicken` function uses OpenGL commands to draw a chicken on the screen based on its position.
