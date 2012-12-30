#include "segment.h"
#include "time.h"

trajectory_change_event::trajectory_change_event(trajectory t) {
    p_frame = gametime::frame+1;
    p_new_trajectory = t;
}

void segment::respond_to_trajectory_change() {
    for (int i = 0; i < trajectory_change_event_que.size(); i++)
        if (trajectory_change_event_que[i].frame() == gametime::frame-place)
            if ((current_trajectory + 2) % 4 != trajectory_change_event_que[i].new_trajectory())
                current_trajectory = trajectory_change_event_que[i].new_trajectory();
}

segment::segment(int x, int y, unsigned p, trajectory t) : block(x, y) {
    current_trajectory = t;
    place = p;
}

void segment::update() {
    respond_to_trajectory_change();
    if      (current_trajectory == ::up)
        up(1);
    else if (current_trajectory == ::down)
        down(1);
    else if (current_trajectory == ::left)
        left(1);
    else if (current_trajectory == ::right)
        right(1);
}

void change_trajectory(trajectory t) {
    if (trajectory_change_event_que.size() == 0 || trajectory_change_event_que[trajectory_change_event_que.size()-1].frame() != gametime::frame+1)
        trajectory_change_event_que.push_back(trajectory_change_event(t));
}
