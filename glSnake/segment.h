#ifndef __glSnake__segment__
#define __glSnake__segment__

#include "block.h"
#include "time.h"

class segment : public block {
    
    trajectory current_trajectory;
    unsigned place;
    
    void respond_to_trajectory_change();
    
public:
    segment(int = 0, int = 0, unsigned = 0, trajectory = ::right);
    void update();
};

void change_trajectory(trajectory);



#endif
