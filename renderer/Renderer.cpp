//
// Created by Will Pease on 11/25/17.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Renderer.h"

void Renderer::render(BoardState *board_state) {
    // Don't do this on the arduino
    std::cout << "Board state" << std::endl;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            char val = (*board_state)[i][j];
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Renderer::diffs(BoardState *old_board_state, BoardState *new_board_state, std::vector<DiffDescription *> *diffs) {
    for(int y=0; y<10; y++) {
        for(int x=0; x<10; x++) {
            char old_value = (*old_board_state)[y][x];
            char new_value = (*new_board_state)[y][x];
            if(new_value != old_value) {
                DiffDescription *diff_desc = new DiffDescription(x, y, (*new_board_state)[y][x]);
                diffs->push_back(diff_desc);
            }
        }
    }
}

void Renderer::render_diffs(BoardState *old_board_state, std::vector<DiffDescription *> *diffs) {
    // This won't be necessary in Arduino
    for(int i=0; i<diffs->size(); i++) {
        DiffDescription *diff = (*diffs)[i];
        (*old_board_state)[diff->pos_y][diff->pos_x] = diff->val;
    }
    this->render(old_board_state);
}
