#ifndef __glSnake__block__
#define __glSnake__block__

#include "mainhead.h"

class block {
protected:
    vec2f pos;
    vec2f size;
    coord2f coord;
    
public:
    block(int = 0, int = 0);
    
    void right(int);
    void left(int n) {right(-n);}
    void up(int);
    void down(int n) {up(-n);}
    
    void render();
    coord2f getCoord() {return coord;}
};

#endif
