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

void jacob(){
    
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
}

void jacobInverse(){
    
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
    
    
    //Inverse
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.86, 0.32, 0.15);
    glVertex3f(-.75, 0, (.75/sqrt(2.0)));
    glVertex3f(.75, 0, (.75/sqrt(2.0)));
    glVertex3f(0, -.75, (-.75/sqrt(2.0)));
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.95, 0.42, 0.14);
    glVertex3f(.75, 0, (.75/sqrt(2.0)));
    glVertex3f(0, -.75, (-.75/sqrt(2.0)));
    glVertex3f(0, .75, (-.75/sqrt(2.0)));
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.58, 0.58, 0.6);
    glVertex3f(0, -.75, (-.75/sqrt(2.0)));
    glVertex3f(0, .75, (-.75/sqrt(2.0)));
    glVertex3f(-.75, 0, (.75/sqrt(2.0)));
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3b(1, 1, 1);
    glColor3f(0.88, 0.85, 0.82);
    glVertex3f(0, .75, (-.75/sqrt(2.0)));
    glVertex3f(-.75, 0, (.75/sqrt(2.0)));
    glVertex3f(.75, 0, (.75/sqrt(2.0)));
    glEnd();

    if (autoRotate) {
        rotate_x +=1;
        rotate_y +=1;
        glutPostRedisplay();
    }
    
}

