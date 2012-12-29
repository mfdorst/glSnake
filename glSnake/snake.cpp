#include "snake.h"

snake::snake() {
    body.push_back(segment( 0, 0, 0));
    body.push_back(segment(-1, 0, 1));
    body.push_back(segment(-2, 0, 2));
    body.push_back(segment(-3, 0, 3));
    body.push_back(segment(-4, 0, 4));
}

void snake::update() {
    for (int i = 0; i < body.size(); i++) {
        body[i].update();
    }
}

void snake::render() {
    for (int i = 0; i < body.size(); i++) {
        body[i].render();
    }
}
