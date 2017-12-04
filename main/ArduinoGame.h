#include <ArduinoSTL.h>

//
// Created by Will Pease on 11/26/17.
//

#ifndef ARDUINO_SNAKE_ARDUINOGAME_H
#define ARDUINO_SNAKE_ARDUINOGAME_H


#include "ArduinoInputReader.h"
#include "GameManager.h"
#include "ArduinoRenderer.h"

class ArduinoGame {
private:
    ArduinoInputReader *arduino_input_reader;
    GameManager *game_manager;
    ArduinoRenderer *arduino_renderer;
    BoardState *current_board_state;
    BoardState *prev_board_state;
    InputState input_state;
    std::vector<DiffDescription *> diffs;
public:
    ArduinoGame();
    void read_input();
    void render_initial();
    void move_and_render();
};


#endif //ARDUINO_SNAKE_ARDUINOGAME_H
