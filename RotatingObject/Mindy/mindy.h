#include <iostream>
#include <stdlib.h>

void teapot(bool isSolid) {
    if(!isSolid){
        glColor3f(1,0.0,0.0);
        glPushMatrix();
        glutWireTeapot(.5);
        glPopMatrix();
    } else {
        glColor3f(1,0.0,0.0);
        glPushMatrix();
        glutSolidTeapot(.5);
        glPopMatrix();
    }
    
    if (autoRotate) {
        rotate_x +=.5;
        rotate_y +=.5;
        glutPostRedisplay();
    }
}

void torus(bool isSolid){
    
    if(!isSolid){
        glColor3f(1,1.0,0.0);
        glPushMatrix();
        glutWireTorus(.1, .5, 5, 20);
        glPopMatrix();
    } else {
        glColor3f(1,1.0,0.0);
        glPushMatrix();
        glutSolidTorus(.1, .5, 5, 20);
        glPopMatrix();
    }
    
    if (autoRotate) {
        rotate_x +=.5;
        rotate_y +=.5;
        glutPostRedisplay();
    }
}


