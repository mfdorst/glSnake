#include "block.h"

block::block(int coordx, int coordy) {
    size.x = 0.015;
    size.y = 0.015*14.4/9;
    pos.x = coordx*size.x*2;
    pos.y = coordy*size.y*2;
    coord.x = coordx;
    coord.y = coordy;
}

void block::right(int n) {
    pos.x += n*size.x*2;
    coord.x += n;
}

void block::up(int n) {
    pos.y += n*size.y*2;
    coord.y += n;
}

void block::render() {
    glPushMatrix();
    glTranslatef(pos.x, pos.y, 0);
    glBegin(GL_QUADS);
    {
        glColor3f(1, 1, 1);
        glVertex2f(-size.x, -size.y);
        glVertex2f( size.x, -size.y);
        glVertex2f( size.x,  size.y);
        glVertex2f(-size.x,  size.y);
    }
    glEnd();
    glPopMatrix();
}
