//
// Created by Will Pease on 11/25/17.
//

#ifndef ARDUINO_SNAKE_RENDERER_H
#define ARDUINO_SNAKE_RENDERER_H


#include <vector>
#include "../game/BoardState.h"
#include "DiffDescription.h"

class Renderer {
public:
    virtual void render(BoardState *board_state);
    void diffs(BoardState *old_board_state, BoardState *new_board_state, std::vector<DiffDescription *> *diffs);
    virtual void render_diffs(BoardState *old_board_state, std::vector<DiffDescription *> *diffs);
};


#endif //ARDUINO_SNAKE_RENDERER_H
