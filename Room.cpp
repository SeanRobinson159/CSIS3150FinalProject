//Making a room.

#include <iostream>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display();
void specialKeys();

double rotate_x=0;
double rotate_y=0;
//*****************************
int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Simple Room");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    //glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
//*****************************

void diplay(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);   glVertex3f( 5,-5,-5);
    glColor3f(0,1,0);   glVertex3f( 5, 5,-5);
    glColor3f(1,0,1);   glVertex3f(-5, 5,-5);
    glColor3f(1,0,1);   glVertex3f(-5,-5,-5);

}
void specialKeys(){
    
}

