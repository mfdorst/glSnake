#include "snake.h"
#include "time.h"

void handleKeypress(unsigned char, int, int);
void handleSpecialKeypress(int, int, int);
void displayFunc();
void updateFunc(int);

snake snakey;

unsigned gametime::frame = 0;
std::vector<trajectory_change_event> trajectory_change_event_que;

const unsigned framerate = 67;

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    
    glutInitWindowSize(720, 450);
    glutCreateWindow("Snake");
    
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(handleSpecialKeypress);
    
    glutDisplayFunc(displayFunc);
    
    glutTimerFunc(framerate, updateFunc, 0);
    
    glutMainLoop();
    
    return 0;
}

void displayFunc() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    snakey.render();
    
    glFlush();
}

void updateFunc(int) {
    
    gametime::frame++;
    snakey.update();
    snakey.render();
    
    glutPostRedisplay();
    glutTimerFunc(framerate, updateFunc, 0);
}

void handleKeypress(unsigned char key, int, int) {
    if (key == 'w')
        change_trajectory(up);
    if (key == 's')
        change_trajectory(down);
    if (key == 'a')
        change_trajectory(left);
    if (key == 'd')
        change_trajectory(right);
    if (key == 'F') {
        static bool fullscreen = false;
        fullscreen = !fullscreen;
        if (!fullscreen) glutReshapeWindow(720, 450);
        if (fullscreen) glutFullScreen();
    }
}

void handleSpecialKeypress(int key, int, int) {
    if (key == GLUT_KEY_UP)
        change_trajectory(up);
    if (key == GLUT_KEY_DOWN)
        change_trajectory(down);
    if (key == GLUT_KEY_LEFT)
        change_trajectory(left);
    if (key == GLUT_KEY_RIGHT)
        change_trajectory(right);
}
