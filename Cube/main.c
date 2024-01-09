//
//  main.c
//  cube_vscode
//
//  Created by Jakob Balkovec on 11/05/2022.
//

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


// Variable to store the width of the cube
float cubeWidth = 20;

// Variable to store the width of the screen
int width = 160;

// Variable to store the height of the screen
int height = 44;

// Variable to store the ASCII code for the background character
int backgroundASCIICode = ' ';

// Variable to store the distance of the cube from the camera
int distanceFromCam = 100;

// Variable to store the horizontal offset of the cube
float horizontalOffset = 0;

// Variable to store the constant K1
float K1 = 40;

// Variable to store the speed at which the cube increments
float incrementSpeed = 0.6;

// Buffers
// This array represents the z-buffer used for depth testing in computer graphics.
// It stores the depth values of each pixel in a 160x44 resolution frame.
float zBuffer[160 * 44];

// This array represents the buffer used for storing characters in computer graphics.
// It stores the ASCII characters of each pixel in a 160x44 resolution frame.
char buffer[160 * 44];

/**
 * Calculates the value of X based on the given parameters.
 *
 * @param i The value of i.
 * @param j The value of j.
 * @param k The value of k.
 * @return The calculated value of X.
 */
float calculateX(int i, int j, int k) {
  return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
    j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

/**
 * Calculates the y-coordinate of a surface based on the given parameters.
 *
 * @param i The value of i.
 * @param j The value of j.
 * @param k The value of k.
 * @return The calculated y-coordinate.
 */
float calculateY(int i, int j, int k) {
  return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
    j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
    i * cos(B) * sin(C);
}

/**
 * Calculates the Z-coordinate of a point in 3D space.
 *
 * @param i The X-coordinate of the point.
 * @param j The Y-coordinate of the point.
 * @param k The Z-coordinate of the point.
 * @return The calculated Z-coordinate.
 */
float calculateZ(int i, int j, int k) {
  return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

/**
 * Calculates the screen coordinates for a given point on the surface of a cube.
 *
 * @param cubeX The x-coordinate of the cube.
 * @param cubeY The y-coordinate of the cube.
 * @param cubeZ The z-coordinate of the cube.
 * @param ch The character to be displayed on the screen at the calculated coordinates.
 */
void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
  float x = calculateX(cubeX, cubeY, cubeZ);
  float y = calculateY(cubeX, cubeY, cubeZ);
  float z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;
  
  float ooz = 1 / z;
  
  int xp = (int)(width / 2 + horizontalOffset + K1 * ooz * x * 2);
  int yp = (int)(height / 2 + K1 * ooz * y);
  
  int idx = xp + yp * width;
  if (idx >= 0 && idx < width * height) {
    if (ooz > zBuffer[idx]) {
      zBuffer[idx] = ooz;
      buffer[idx] = ch;
    }
  }
}

/**
 * @brief Generates a spinning cube animation on the terminal screen.
 *        The cube consists of three layers, each with a different size.
 *        The animation continuously rotates the cube and updates the display.
 */
void generateSpinningCube() {
  // Clear the screen
  printf("\x1b[2J");

  while (1) {
    // Clear the buffer and zBuffer
    memset(buffer, backgroundASCIICode, width * height);
    memset(zBuffer, 0, width * height * 4);

    // First cube
    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
        calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
      }
    }

    // Update cube size and offset for the second layer
    cubeWidth = 10;
    horizontalOffset = 1 * cubeWidth;

    // Second cube
    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
        calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
      }
    }

    // Update cube size and offset for the third layer
    cubeWidth = 5;
    horizontalOffset = 8 * cubeWidth;

    // Third cube
    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
        calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
        calculateForSurface(cubeWidth, cubeY, cubeX, '$');
        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
        calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
        calculateForSurface(cubeX, cubeWidth, cubeY, '+');
      }
    }

    // Print the buffer to the terminal screen
    printf("\x1b[H");
    for (int k = 0; k < width * height; k++) {
      putchar(k % width ? buffer[k] : 10);
    }

    // Update rotation angles and delay
    A += 0.05;
    B += 0.05;
    C += 0.01;
    usleep(8000 * 2);
  }
}

/**
 * @brief The main function of the program.
 * 
 * This function calls the generateSpinningCube() function and returns 0.
 * 
 * @return 0 indicating successful program execution.
 */
int main() {
  generateSpinningCube();
  return 0;
}
