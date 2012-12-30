#ifndef __glSnake__snake__
#define __glSnake__snake__

#include "segment.h"

#include <vector>

class snake {
    
    std::vector<segment*> body;
    
public:
    
    snake();
    collision checkCollision();
    void update();
    void render();
};

#endif
