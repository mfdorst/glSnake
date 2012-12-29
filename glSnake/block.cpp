#include "block.h"

block::block(int posx, int posy) {
    size.x = 0.015;
    size.y = 0.015*14.4/9;
    pos.x = posx*size.x*2;
    pos.y = posy*size.y*2;
}

void block::right(int n) {
    pos.x += n*size.x*2;
}

void block::up(int n) {
    pos.y += n*size.y*2;
}

void block::render() {
    glPushMatrix();
    glTranslatef(pos.x, pos.y, 0);
    glBegin(GL_LINE_LOOP);
    {
        glColor3f(0, 0, 0);
        glVertex2f(-size.x, -size.y);
        glVertex2f( size.x, -size.y);
        glVertex2f( size.x,  size.y);
        glVertex2f(-size.x,  size.y);
    }
    glEnd();
    glPopMatrix();
}
