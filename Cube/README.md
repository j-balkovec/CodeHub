# Spinning Cube
This simple program generates a spinning cube using ASCII characters in the terminal. The cube rotates around its axes, creating a visually appealing animation. Below is an explanation of the code and how it works.

## Code Explanation
### Global Variables
`A`, `B`, and `C`: Global variables representing the rotation angles around the X, Y, and Z axes.
`cubeWidth`: Width of the cube.
`width` and `height`: Dimensions of the terminal window.
`backgroundASCIICode`: ASCII code for the background character.
`distanceFromCam`: Distance of the cube from the camera.
`horizontalOffset`: Offset for positioning cubes horizontally.
`K1`: Constant used for scaling.
`incrementSpeed`: Incremental speed for cube generation.

### Buffers
`zBuffer`: A buffer to store the Z-values for each pixel.
`buffer`: A character buffer to store ASCII characters for display.

## Surface Calculation Functions
`calculateX`, `calculateY`, `calculateZ`: Functions to calculate the coordinates of a surface based on the cube's position and rotation angles.
`calculateForSurface`: Function to calculate coordinates, update character buffer, and Z-buffer for a surface.

## Cube Generation Function
`generateSpinningCube`: Function to generate the spinning cube animation. It uses nested loops to calculate and update the buffers for each surface of the cube. The program continuously updates and prints the cube's animation.

## Main Function
The main function calls the generateSpinningCube function to start the spinning cube animation.

## How to Run
Compile and run the program using a C compiler:

```
gcc spinning_cube.c -o spinning_cube -lm
./spinning_cube
```

The spinning cube animation will be displayed in the terminal.
