#include "snake.h"

snake::snake() {
    grow = false;
    body.push_back(new segment( 0, 0, 0));
    body.push_back(new segment(-1, 0, 1));
    body.push_back(new segment(-2, 0, 2));
    body.push_back(new segment(-3, 0, 3));
    body.push_back(new segment(-4, 0, 4));
    body.push_back(new segment(-5, 0, 5));
}

void snake::update() {
    for (int i = 0; i < body.size(); i++) {
        body[i]->update();
    }
    if (grow) {
        body.push_back(growth);
        grow = false;
    }
}

void snake::render() {
    for (int i = 0; i < body.size(); i++) {
        body[i]->render();
    }
}

collision snake::checkCollision(block morsel) {
    /* wall collisions */
    coord2i bcoord = morsel.getCoord();
    coord2i scoord = body[0]->getCoord();
    trajectory t = body[0]->getTrajectory();
    if (scoord.x <= -34 || scoord.x >= 34 || scoord.y <= -21 || scoord.y >= 21)
        return wall;
    /* food collisions */
    if (t == up && scoord.y == bcoord.y && scoord.x == bcoord.x)
        return food;
    if (t == down && scoord.y == bcoord.y && scoord.x == bcoord.x)
        return food;
    if (t == right && scoord.x == bcoord.x && scoord.y == bcoord.y)
        return food;
    if (t == left && scoord.x == bcoord.x && scoord.y == bcoord.y)
        return food;
    for (int i = 3; i < body.size(); i++) {
        bcoord = body[i]->getCoord();
        if (t == up && scoord.y == bcoord.y && scoord.x == bcoord.x)
            return wall;
        if (t == down && scoord.y == bcoord.y && scoord.x == bcoord.x)
            return wall;
        if (t == right && scoord.x == bcoord.x && scoord.y == bcoord.y)
            return wall;
        if (t == left && scoord.x == bcoord.x && scoord.y == bcoord.y)
            return wall;
    }
    return none;
}

void snake::add() {
    coord2i coord = body[body.size()-1]->getCoord();
    trajectory t = body[body.size()-1]->getTrajectory();
    growth = new segment(coord.x, coord.y, (int)body.size(), t);
    grow = true;
}
