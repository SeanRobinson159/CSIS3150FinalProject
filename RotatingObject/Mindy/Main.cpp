#ifndef SHAPEHEADER_H_INCLUDED
#define SHAPEHEADER_H_INCLUDED
#endif // SHAPEHEADER_H_INCLUDED

#include <iostream>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__    //If it is an Apple device
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <stdlib.h>



void teapot() {
glColor3f(1,0.0,0.0);
glPushMatrix();
glutWireTeapot(.5);
glPopMatrix();

    if (autoRotate) {
        rotate_x +=1;
        rotate_y +=1;
        glutPostRedisplay();
    }
}
