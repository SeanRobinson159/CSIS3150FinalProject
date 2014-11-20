#include "Sean/Cube/sean.cpp"
#include "Mindy/mindy.cpp"
#include "Jacob/Jacob/jacob.cpp"

void specialKeys();
void display();

bool openCube;
bool openJacob;
bool openJacob2;
bool openMindy;

bool change;

void display(){
    //  Clear screen and Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Rotate when user changes rotate_x and rotate_y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    //Which object to open
    if (openCube) {
        cube();
    } else if (openJacob){
        jacob();
    }else if (openMindy){
        teapot();
    }else if (openJacob2){
        jacobInverse();
    }
    glFlush();
    glutSwapBuffers();
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

    switch (key) {  //Which object to open
        case 49:    //Number 1
            if (!openCube){
                openCube = true;
                openMindy = openJacob = false;
            }
            else {
                openCube = false;
            }
            break;

        case 50:    //Number 2
            if (!openJacob) {
                openJacob = true;
                openCube = openMindy = false;
            }
            else {
                openJacob = false;
            }
            break;

        case 51:    //Number 3
            if(!openMindy) {
                openMindy = true;
                openJacob = openCube = false;
            }
            else {
                openMindy = false;
            }
            break;
            
        case 52:    //Number 4
            if (!openJacob) {
                openJacob2 = true;
                openCube = openMindy = false;
            }
            else {
                openJacob2 = false;
            }
            break;
            
        case 119:    //w
            if(!change) {
                change = true;
            }
            else {
                change = false;
            }
            break;

        case 114:    //r
            rotate_x = 0;
            rotate_y = 0;
            break;
        default:
            break;
    }
    //  Request display update
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    glutInitWindowSize(800,800);
    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);
    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Create window
    glutCreateWindow("Rotating Objects");
    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);
    // Callback functions
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    //  Pass control to GLUT for events
    glutMainLoop();
}
