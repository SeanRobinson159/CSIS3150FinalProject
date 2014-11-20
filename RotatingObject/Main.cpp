#include "rotatingObjects.h"

//Setting up methods
void specialKeys();
void display();
void openObject();
void displayMenu(float x, float y, float r, float g, float b, void *font, const char *string);

//Setting up variables
bool showMenu = true;
bool openCube;
bool openTetrahedron;
bool openHypertetrahedron;
bool openTeapot;
bool openTorus;
bool isSolid;

void displayMenu(float x, float y, float r, float g, float b, void *font, const char *string){
    glColor3f( r, g, b );
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void display(){
    //  Clear screen and Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    // Reset transformations
    glLoadIdentity();
    // Rotate when user changes rotate_x and rotate_y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    
    //Which object to open
    openObject();
    
    glFlush();
    glutSwapBuffers();
}

void openObject(){
    if (showMenu) {
        displayMenu(-0.2, 0.5,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "1: Cube");
        displayMenu(-0.2, 0.4,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "2: Tetrahedron");
        displayMenu(-0.2, 0.3,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "3: Teapot");
        displayMenu(-0.2, 0.2,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "4: Hypertetrahedron");
        displayMenu(-0.2, 0.1,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "5: Torus");
        displayMenu(-0.2, 0.0,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "W: Wireframe");
        displayMenu(-0.2,-0.1,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "R: Reset Rotate");
        displayMenu(-0.2,-0.2,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "M: Menu");
        displayMenu(-0.2,-0.3,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "ESC: Exit");
        displayMenu(-0.2,-0.4,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "Rotate with arrow keys");
        displayMenu(-0.2,-0.5,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "(Auto Rotate with Spacebar)");
    } else
        if (openCube) {
        cube();
    } else if (openTetrahedron){
        tetrahedron();
    }else if (openTeapot){
        teapot(isSolid);
    }else if (openTorus){
        torus(isSolid);
    }else if (openHypertetrahedron){
        hypertetrahedron();
    }
}

void keyBinding(int key){
    switch (key) {  //Which object to open
        case 49:    //Number 1
            openCube = !openCube;
            showMenu = openTorus = openTetrahedron = openHypertetrahedron = openTeapot = false;
            break;
        case 50:    //Number 2
            openTetrahedron = !openTetrahedron;
            showMenu = openTorus = openCube = openHypertetrahedron = openTeapot = false;
            break;
        case 51:    //Number 3
            openTeapot = !openTeapot;
            showMenu = openTorus = openTetrahedron = openHypertetrahedron = openCube = false;
            break;
        case 52:    //Number 4
            openHypertetrahedron = !openHypertetrahedron;
            showMenu = openTorus = openTetrahedron = openCube = openTeapot = false;
            break;
        case 53:    //Number 5
            openTorus = !openTorus;
            showMenu = openTetrahedron = openHypertetrahedron = openCube = openTeapot = false;
            break;
        case 114:    //letter r
            rotate_x = 0;
            rotate_y = 0;
            break;
        case 109:    //letter m
            rotate_x = 0;
            rotate_y = 0;
            showMenu = !showMenu;
            break;
        case 119:    //letter w
            isSolid = !isSolid;
            break;
            
        default:
            break;
    }
    
}

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
        if (autoRotate) autoRotate = false;
        else autoRotate = true;
    }
    keyBinding(key);
    //  Request display update
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    // Setting the window size
    glutInitWindowSize(800,800);
    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);
    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Create window
    glutCreateWindow("Rotating Objects – OpenGL");
    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);
    // Callback functions
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    //  Pass control to GLUT for events
    glutMainLoop();
}
