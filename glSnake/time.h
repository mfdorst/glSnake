#ifndef __glSnake__time__
#define __glSnake__time__

#include <vector>

namespace gametime {
    
    extern unsigned frame;
    
}

typedef enum { up, right, down, left } trajectory;
typedef enum { wall, food, none } collision;

class trajectory_change_event {
    unsigned p_frame;
    trajectory p_new_trajectory;
public:
    trajectory_change_event(trajectory);
    unsigned frame()const {return p_frame;}
    trajectory new_trajectory()const {return p_new_trajectory;}
};

extern std::vector<trajectory_change_event> trajectory_change_event_que;

#endif
