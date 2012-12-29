#include "snake.h"
#include "time.h"

void handleKeypress(unsigned char, int, int);
void displayFunc();
void updateFunc(int);

snake snakey;

unsigned gametime::frame = 0;
std::vector<trajectory_change_event> trajectory_change_event_que;

const unsigned framerate = 67;

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    
    glutCreateWindow("Snake");
    
    glutFullScreen();
    
    glutKeyboardFunc(handleKeypress);
    
    glutDisplayFunc(displayFunc);
    
    glutTimerFunc(framerate, updateFunc, 0);
    
    glutMainLoop();
    
    return 0;
}

void displayFunc() {
    glClearColor(1, 1, 1, 1);
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
        trajectory_change_event_que.push_back(trajectory_change_event(up));
    if (key == 's')
        trajectory_change_event_que.push_back(trajectory_change_event(down));
    if (key == 'a')
        trajectory_change_event_que.push_back(trajectory_change_event(left));
    if (key == 'd')
        trajectory_change_event_que.push_back(trajectory_change_event(right));
}
