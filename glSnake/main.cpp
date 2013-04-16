#include "snake.h"
#include "time.h"
#include <cstdlib>

void handleKeypress(unsigned char, int, int);
void handleSpecialKeypress(int, int, int);
void displayFunc();
void updateFunc(int);

snake snakey;
block morsel;
vec3f yellow = {1,1,0};
vec3f green = {0,1,0};

unsigned gametime::frame = 0;
std::vector<trajectory_change_event> trajectory_change_event_que;

const unsigned framerate = 64;

int main(int argc, char** argv) {
    
    srand((unsigned)time(NULL));
    
    morsel.setCoord((rand() % 66)-33, (rand() % 40)-20);
    
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
    
    glBegin(GL_QUADS);
    {
        glColor3f(0.3, 0.3, 0.3);
        glVertex2d(-1, 1);
        glColor3f(0.15, 0.15, 0.15);
        glVertex2d(-1, -1);
        glColor3f(0, 0, 0);
        glVertex2d(1, -1);
        glColor3f(0.15, 0.15, 0.15);
        glVertex2d(1, 1);
    }
    glEnd();
    
    snakey.render();
    morsel.render(GL_LINE_LOOP, green);
    
    glFlush();
}

void updateFunc(int) {
    
    gametime::frame++;
    snakey.update();
    if (snakey.checkCollision(morsel) == wall)
        return;
    else if (snakey.checkCollision(morsel) == food) {
        snakey.add();
        morsel.setCoord((rand() % 66)-33, (rand() % 40)-20);
    }
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
