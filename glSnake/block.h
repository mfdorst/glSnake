#ifndef __glSnake__block__
#define __glSnake__block__

#include "mainhead.h"

class block {
    
    vec2f pos;
    vec2f size;
    
public:
    block();
    
    void right(int);
    void left(int n) {right(-n);}
    void up(int);
    void down(int n) {up(-n);}
    
    void render();
};

#endif
