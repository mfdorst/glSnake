#include "snake.h"

snake::snake() {
    body.push_back(new segment( 0, 0, 0));
    body.push_back(new segment(-1, 0, 1));
    body.push_back(new segment(-2, 0, 2));
    body.push_back(new segment(-3, 0, 3));
    body.push_back(new segment(-4, 0, 4));
}

void snake::update() {
    for (int i = 0; i < body.size(); i++) {
        body[i]->update();
    }
}

void snake::render() {
    for (int i = 0; i < body.size(); i++) {
        body[i]->render();
    }
}

collision snake::checkCollision() {
    /* wall collisions */
    coord2f coord = body[0]->getCoord();
    if (coord.x <= -34 || coord.x >= 34 || coord.y <= -21 || coord.y >= 21)
        return wall;
    return none;
}
