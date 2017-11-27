//
// Created by Will Pease on 11/25/17.
//

#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(int x, int y) {
    this->pos_x = x;
    this->pos_y = y;
}

void SnakeSegment::move() {
    // Not actually needed.
}

void SnakeSegment::render(BoardState *board_state) {
    (*board_state)[pos_y][pos_x] = 's';
}
