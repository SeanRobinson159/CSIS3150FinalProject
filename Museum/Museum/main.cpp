//
//  main.cpp
//  Museum
//
//  Created by Sean Robinson on 11/13/14.
//  Copyright (c) 2014 Sean Robinson. All rights reserved.
//
//Making a room.

#include <iostream>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void rect(float x, float y, float z, float xThickness);
void render(void);
void specialKeys();

double rotate_x=0;
double rotate_y=0;


void render(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    
    //Right Box
    glColor3f(0, 0, 1);
    rect(-.5, .5, .5, 1);
    
    glFlush();
    glutSwapBuffers();
    
}
void specialKeys( int key, int x, int y ) {
    
    //  Right arrow - increase rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    
    //  Left arrow - decrease rotation by 5 degree
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    
    else if (key == 27)
        exit(0);
    
    //  Request display update
    glutPostRedisplay();
    
}
void rect(float x, float y, float z, float xThickness){
    glBegin(GL_POLYGON);
    glVertex3f( x, -y, -z );  //inner
    glVertex3f( x,  y, -z );
    glVertex3f( x,  y,  z );
    glVertex3f( x, -y,  z );
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f( x+xThickness, -y, -z ); //outer
    glVertex3f( x+xThickness,  y, -z );
    glVertex3f( x+xThickness,  y,  z );
    glVertex3f( x+xThickness, -y,  z );
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f( x,    y, -z );    //top
    glVertex3f( x+xThickness,   y, -z );
    glVertex3f( x+xThickness,   y,  z );
    glVertex3f( x,    y,  z );
    glEnd();
    
    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
    glVertex3f( x,    -y, -z );   //bottom
    glVertex3f( x+xThickness,   -y, -z );
    glVertex3f( x+xThickness,   -y,  z );
    glVertex3f( x,    -y,  z );
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f( x,    -y, -z );   //front
    glVertex3f( x+xThickness,   -y, -z );
    glVertex3f( x+xThickness,   y,  -z );
    glVertex3f( x,    y,  -z );
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f( x,   -y,  z );  //back
    glVertex3f( x+xThickness,   -y,  z );
    glVertex3f( x+xThickness,    y,  z );
    glVertex3f( x,    y,  z );
    glEnd();
}


//*****************************
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Simple Room");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
}
//*****************************
