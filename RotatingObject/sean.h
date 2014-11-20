
void cube() {
    //Red - FRONT
    glBegin(GL_POLYGON);
    glColor3f(   .72,  .07,  .20 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    // Orange side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  .35, 0.0 );
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
    
    // White side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  1.0,  1.0 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();
    
    // Yellow side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  .84,  0.0 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    // Green side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  .61,  .28 );
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();
    
    // Blue side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  .27,  .67 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    if (autoRotate) {
        rotate_x +=.5;
        rotate_y +=.5;
        glutPostRedisplay();
    }
}