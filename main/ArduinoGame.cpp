//
// Created by Will Pease on 11/26/17.
//

//#include <cstdlib>
#include "ArduinoGame.h"

ArduinoGame::ArduinoGame() {
    this->arduino_input_reader = new ArduinoInputReader(40, 41, 42, 43, 44, 45, 46, 47);
    this->game_manager = new GameManager();
    this->arduino_renderer = new ArduinoRenderer();
    this->current_board_state = (BoardState *)malloc(sizeof(BoardState));
    this->prev_board_state = (BoardState *)malloc(sizeof(BoardState));
}

void ArduinoGame::read_input() {
    this->arduino_input_reader->read_input(&this->input_state);
    this->game_manager->apply_input(&this->input_state);
}

void ArduinoGame::render_initial() {
    this->game_manager->render(current_board_state);
    this->game_manager->render(prev_board_state);
    this->arduino_renderer->render(current_board_state);
}

void ArduinoGame::move_and_render() {
    this->game_manager->move();
    this->game_manager->render(current_board_state);
    this->arduino_renderer->diffs(prev_board_state, current_board_state, &diffs);
    this->arduino_renderer->render_diffs(&diffs);
    for(DiffDescription *diff_desc : diffs) {
        delete diff_desc;
    }
    diffs.clear();

    // Swap boards
    BoardState *temp = this->prev_board_state;
    this->prev_board_state = this->current_board_state;
    this->current_board_state = temp;

    // Clear input
    input_state.clear();
}
