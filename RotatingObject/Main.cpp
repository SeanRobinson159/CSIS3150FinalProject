#ifdef __APPLE__	//If it is running on an Apple device
    #include <GLUT/glut.h>
#else				//If it is running on anything else
    #include <GL/glut.h>
#endif

#include "Sean/Cube/sean.cpp"
#include "Mindy/mindy.cpp"
#include "Jacob/Jacob/jacob.cpp"

//Setting up methods
void specialKeys();
void display();
void openObject();
void displayMenu(float x, float y, float r, float g, float b, void *font, char *string);

//Setting up variables
bool showMenu;
bool openCube;
bool openJacob;
bool openJacob2;
bool openMindy;

void displayMenu(float x, float y, float r, float g, float b, void *font, char *string){
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
        displayMenu(-0.2, 0.1,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "1: Cube");
        displayMenu(-0.2,-0.0,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "2: Tetrahedron");
        displayMenu(-0.2,-0.1,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "3: Teapot");
        displayMenu(-0.2,-0.2,1.0,1.0,1.0,GLUT_BITMAP_HELVETICA_18, "4: Hypertetrahedron");
    } else
        if (openCube) {
        cube();
    } else if (openJacob){
        jacob();
    }else if (openMindy){
        teapot();
    }else if (openJacob2){
        jacob2();
    }
}

void keyBinding(int key){
    switch (key) {  //Which object to open
        case 49:    //Number 1
            openCube = !openCube;
            showMenu = openJacob = openJacob2 = openMindy = false;
            break;
            
        case 50:    //Number 2
            openJacob = !openJacob;
            showMenu = openCube = openJacob2 = openMindy = false;
            break;
            
        case 51:    //Number 3
            openMindy = !openMindy;
            showMenu = openJacob = openJacob2 = openCube = false;
            break;
            
        case 52:    //Number 4
            openJacob2 = !openJacob2;
            showMenu = openJacob = openCube = openMindy = false;
            break;
            
        case 114:    //r
            rotate_x = 0;
            rotate_y = 0;
            break;
            
        case 109:    //m
            rotate_x = 0;
            rotate_y = 0;
            showMenu = !showMenu;
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
    glutInitWindowSize(800,800);
    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);
    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Create window
    glutCreateWindow("***Awesome Objects!***");
    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);
    // Callback functions
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    //  Pass control to GLUT for events
    glutMainLoop();
}
