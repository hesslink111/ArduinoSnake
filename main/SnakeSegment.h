//
// Created by Will Pease on 11/25/17.
//

#ifndef ARDUINO_SNAKE_SNAKE_SEGMENT_H
#define ARDUINO_SNAKE_SNAKE_SEGMENT_H


#include "Entity.h"

class SnakeSegment : public Entity {

public:
    SnakeSegment(int x, int y);

    void move() override;
    void render(BoardState *board_state) override;
};


#endif //ARDUINO_SNAKE_SNAKE_SEGMENT_H
