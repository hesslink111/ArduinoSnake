//
// Created by Will Pease on 11/25/17.
//

#include <cstdlib>
#include "Food.h"

Food::Food(int pos_x, int pos_y) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

void Food::move() {
    // Not used
}

void Food::render(BoardState *board_state) {
    (*board_state)[this->pos_y][this->pos_x] = 'f';
}

void Food::randomize_position() {
    this->pos_x = rand() % 10;
    this->pos_y = rand() % 10;
}
