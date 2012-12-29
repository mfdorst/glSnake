#include "snake.h"

void displayFunc();
void updateFunc(int);

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    
    glutCreateWindow("Snake");
    
    glutFullScreen();
    
    glutDisplayFunc(displayFunc);
    
    glutTimerFunc(125, updateFunc, 0);
    
    glutMainLoop();
    
    return 0;
}

void displayFunc() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //...
    
    glFlush();
}

void updateFunc(int x) {
    
    //...
    
    glutPostRedisplay();
    glutTimerFunc(125, updateFunc, 0);
}
