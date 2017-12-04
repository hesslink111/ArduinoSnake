//
// Created by Will Pease on 11/25/17.
//

#ifndef ARDUINO_SNAKE_ENTITY_H
#define ARDUINO_SNAKE_ENTITY_H


#include "BoardState.h"

class Entity {
public:
    int pos_x;
    int pos_y;
    virtual void move() = 0;
    virtual void render(BoardState *board_state) = 0;
    virtual bool has_collided_with(Entity *entity);
    bool is_out_of_bounds();
};


#endif //ARDUINO_SNAKE_ENTITY_H
