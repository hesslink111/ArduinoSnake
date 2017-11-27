//
// Created by Will Pease on 11/25/17.
//

#include <iostream>
#include "Board.h"

Board::Board() {
    this->food = nullptr;
    this->snake = nullptr;
    reset_board();
}

void Board::move() {
    // Move all the entities
    for(int i=0; i<this->entities.size(); i++) {
        entities[i]->move();
    }

    // Check for out of bounds
    if(this->snake->is_out_of_bounds()) {
        // End the game
        this->reset_board();
    }

    // Check for collisions
    if(this->snake->get_head()->has_collided_with(food)) {
        snake->grow();
        while(snake->has_collided_with(food)) {
            food->randomize_position();
        }
    }
}

BoardState *Board::render(BoardState *board_state) {
    // Clear out anything in the board
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            (*board_state)[i][j] = ' ';
        }
    }

    // Render all entities onto the board
    for(int i=0; i<this->entities.size(); i++) {
        entities[i]->render(board_state);
    }

    return board_state;
}

void Board::reset_board() {

    // Remove old stuff
    this->entities.clear();
    delete this->food;
    delete this->snake;

    // Create a food
    this->food = new Food(8, 8);
    this->entities.push_back((Entity *)this->food);

    // Create a snake
    this->snake = new Snake(1, 1, 1, 2, 0, 1);
    this->entities.push_back((Entity *)this->snake);
}
