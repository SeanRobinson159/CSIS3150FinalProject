//
//  main.cpp
//  Jacob
//
//  Created by Jacob Ward on 11/18/14.
//  Copyright (c) 2014 Jacob Ward. All rights reserved.
//

#include <iostream>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES

#ifdef __APPLE__	//If it is running on an Apple device
#include <GLUT/glut.h>
#else				//If it is running on anything else
#include <GL/glut.h>
#endif

void display();
void specialKeys();

double rotate_y=0;
double rotate_x=0;
bool autoRotate=false;

void jacob(){
    
    //glEnable(GL_LIGHTING);
    
    //  Clear screen and Z-buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Rotate when user changes rotate_x and rotate_y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.86, 0.32, 0.15);
    glVertex3f(.75, 0, (-.75/sqrt(2.0)));
    glVertex3f(-.75, 0, (-.75/sqrt(2.0)));
    glVertex3f(0, .75, (.75/sqrt(2.0)));
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.95, 0.42, 0.14);
    glVertex3f(-.75, 0, (-.75/sqrt(2.0)));
    glVertex3f(0, .75, (.75/sqrt(2.0)));
    glVertex3f(0, -.75, (.75/sqrt(2.0)));
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.58, 0.58, 0.6);
    glVertex3f(0, .75, (.75/sqrt(2.0)));
    glVertex3f(0, -.75, (.75/sqrt(2.0)));
    glVertex3f(.75, 0, (-.75/sqrt(2.0)));
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.88, 0.85, 0.82);
    glVertex3f(0, -.75, (.75/sqrt(2.0)));
    glVertex3f(.75, 0, (-.75/sqrt(2.0)));
    glVertex3f(-.75, 0, (-.75/sqrt(2.0)));
    glEnd();

    if (autoRotate) {
        rotate_x +=1;
        rotate_y +=1;
        glutPostRedisplay();
    }
    glFlush();
    glutSwapBuffers();
    
}

/*
// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
    if (key == GLUT_KEY_RIGHT)  //  Right arrow - increase rotation by 5 degree
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT) //  Left arrow - decrease rotation by 5 degree
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    else if (key == 27)     //Esc key
        exit(0);
    else if (key == 32){    //SpaceBar
        if (autoRotate) {
            autoRotate = false;
        } else {
            autoRotate = true;
        }
    }
    //  Request display update
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);
    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Create window
    glutCreateWindow("Testing");
    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);
    // Callback functions
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    //  Pass control to GLUT for events
    glutMainLoop();
    
    //  Return to OS
    return 0;
}
*/