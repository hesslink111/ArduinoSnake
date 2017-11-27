//
// Created by Will Pease on 11/26/17.
//

#ifndef ARDUINO_SNAKE_ARDUINOINPUTREADER_H
#define ARDUINO_SNAKE_ARDUINOINPUTREADER_H


#include "InputState.h"

class ArduinoInputReader {
private:
    int d_up;
    int d_down;
    int d_left;
    int d_right;
    int reset;
    int start;
    int b;
    int a;
public:
    ArduinoInputReader(int d_up, int d_down, int d_left, int d_right, int reset, int start, int b, int a);
    void read_input(InputState *input_state);
};


#endif //ARDUINO_SNAKE_ARDUINOINPUTREADER_H
