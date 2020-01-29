#ifndef BOUNCINGSQUARE_H
#define BOUNCINGSQUARE_H

#include "LOpenGL.h"
#include <iostream>

// screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

GLfloat squareX = SCREEN_WIDTH/2.f;
GLfloat squareY = SCREEN_HEIGHT/2.f;

int squareXVel = 5;
int squareYVel = 5;

bool init();
void update();
void render();
void runMainLoop(int val);

#endif