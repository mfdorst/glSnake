#include "snake.h"

#include "block.h"

namespace window {
    const unsigned height = 720;
    const unsigned width = 720;
}

void displayFunc();

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    
    glutInitWindowSize(window::width, window::height);
    
    glutCreateWindow("Snake");
    
    glutDisplayFunc(displayFunc);
    
    glutMainLoop();
    
    return 0;
}

void displayFunc() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_QUADS);
    {
        glColor4f(0, 0, 0, 1);
        glVertex2f(-.02, -.02);
        glVertex2f(0.02, -.02);
        glVertex2f(0.02, 0.02);
        glVertex2f(-.02, 0.02);
    }
    glEnd();
    glFlush();
}
