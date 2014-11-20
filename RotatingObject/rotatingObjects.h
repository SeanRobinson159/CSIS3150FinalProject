#ifdef __APPLE__	//If it is running on an Apple device
#include <GLUT/glut.h>
#else				//If it is running on anything else
#include <GL/glut.h>
#endif

double rotate_y=0;
double rotate_x=0;
bool autoRotate;

#include <stdarg.h>
#include <math.h>
#include <iostream>
#include "sean.h"
#include "mindy.h"
#include "jacob.h"
