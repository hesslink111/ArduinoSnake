//
// Created by Will Pease on 11/25/17.
//

#ifndef ARDUINO_SNAKE_BOARD_H
#define ARDUINO_SNAKE_BOARD_H


#include <vector>
#include "Entity.h"
#include "BoardState.h"
#include "Snake.h"
#include "Food.h"

class Board{

private:
    std::vector<Entity *> entities;
public:
    Snake *snake;
    Food *food;
    Board();
    void move();
    BoardState *render(BoardState *board_state);
    void reset_board();
};


#endif //ARDUINO_SNAKE_BOARD_H
