//
// Created by Will Pease on 11/25/17.
//

#ifndef ARDUINO_SNAKE_SNAKE_H
#define ARDUINO_SNAKE_SNAKE_H


#include <list>
#include "SnakeSegment.h"
#include "Entity.h"

class Snake : public Entity {

private:
    std::list<SnakeSegment *> segments;

    int vect_x;
    int vect_y;

    SnakeSegment *saved_tail;

public:
    Snake(int tail_x, int tail_y, int head_x, int head_y, int vect_x, int vect_y);
    ~Snake();

    void move() override;
    void render(BoardState *board_state) override;

    void set_direction(int vect_x, int vect_y);

    SnakeSegment *get_head();

    void grow();

    bool has_collided_with(Entity *entity) override;
};


#endif //ARDUINO_SNAKE_SNAKE_H
