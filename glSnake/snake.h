#ifndef __glSnake__snake__
#define __glSnake__snake__

#include "segment.h"

#include <vector>

class snake {
    
    std::vector<segment*> body;
    
    bool grow;
    segment *growth;
    
public:
    
    snake();
    collision checkCollision(block);
    void update();
    void render();
    void add();
};

#endif
