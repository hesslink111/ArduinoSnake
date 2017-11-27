//
// Created by Will Pease on 11/26/17.
//

#include "InputState.h"

InputState::InputState() {
    this->d_pad_direc = DIREC_NONE;
    this->reset = BTN_UP;
    this->start = BTN_UP;
    this->b = BTN_UP;
    this->a = BTN_UP;
}
