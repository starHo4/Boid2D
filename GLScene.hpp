#ifndef __GLScene__
#define __GLScene__

#include <iostream>
#include <cmath>
#include <GLUT/glut.h>
#include "Flock.hpp"

using namespace std;

#define FPS 50
#define PI M_PI

void GLScene(int argc, char *argv[]);
void GLScene(int x, int y, int argc, char *argv[]);

void Display();
void Keyboard(unsigned char key, int x, int y);
void Reshape(int w, int h);
void Update(int val);

void Init();

void Render();

#endif