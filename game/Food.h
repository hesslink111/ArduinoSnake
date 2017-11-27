//
// Created by Will Pease on 11/25/17.
//

#ifndef ARDUINO_SNAKE_FOOD_H
#define ARDUINO_SNAKE_FOOD_H


#include "Entity.h"

class Food : public Entity {
public:
    Food(int pos_x, int pos_y);
    void move() override;
    void render(BoardState *board_state) override;
    void randomize_position();
};


#endif //ARDUINO_SNAKE_FOOD_H
