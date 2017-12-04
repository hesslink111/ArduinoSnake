//
// Created by Will Pease on 11/26/17.
//

#ifndef ARDUINO_SNAKE_INPUTSTATE_H
#define ARDUINO_SNAKE_INPUTSTATE_H


#include "Direction.h"
#include "ButtonState.h"

class InputState {
public:
    Direction d_pad_direc;
    ButtonState reset;
    ButtonState start;
    ButtonState b;
    ButtonState a;
    InputState();
    void clear();
};


#endif //ARDUINO_SNAKE_INPUTSTATE_H
