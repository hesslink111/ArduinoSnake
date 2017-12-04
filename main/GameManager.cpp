//
// Created by Will Pease on 11/26/17.
//

#include "GameManager.h"

GameManager::GameManager() {
    this->board = new Board();
    this->apply_reset = false;
}

void GameManager::apply_input(InputState *input_state) {
    // Check d-pad
    switch(input_state->d_pad_direc) {
        case DIREC_LEFT:
            this->board->snake->set_direction(-1, 0);
            break;
        case DIREC_RIGHT:
            this->board->snake->set_direction(1, 0);
            break;
        case DIREC_UP:
            this->board->snake->set_direction(0, -1);
            break;
        case DIREC_DOWN:
            this->board->snake->set_direction(0, 1);
            break;
        case DIREC_NONE:
        default:
            break;
    }

    // Check reset button
    if(input_state->reset == BTN_DOWN) {
        apply_reset = true;
    }
}

void GameManager::move() {
    if(apply_reset) {
        this->board->reset_board();
        this->apply_reset = false;
        return;
    }

    this->board->move();
}

void GameManager::render(BoardState *board_state) {
    this->board->render(board_state);
}
