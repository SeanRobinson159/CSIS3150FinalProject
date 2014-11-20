void tetrahedron(){
    
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
        rotate_x +=.5;
        rotate_y +=.5;
        glutPostRedisplay();
    }
}

void hypertetrahedron(){
    
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
        rotate_x +=.5;
        rotate_y +=.5;
        glutPostRedisplay();
    }
    
}

