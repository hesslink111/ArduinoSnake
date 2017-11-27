//
// Created by Will Pease on 11/26/17.
//

#ifndef ARDUINO_SNAKE_GAMEMANAGER_H
#define ARDUINO_SNAKE_GAMEMANAGER_H


#include "input/InputState.h"
#include "game/BoardState.h"
#include "game/Board.h"

class GameManager {
private:
    Board *board;
    bool apply_reset;
public:
    GameManager();
    void apply_input(InputState *input_state);
    void move();
    void render(BoardState *board_state);
};


#endif //ARDUINO_SNAKE_GAMEMANAGER_H
