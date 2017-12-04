//
// Created by Will Pease on 11/26/17.
//

#include "ArduinoInputReader.h"
#include <Arduino.h>

ArduinoInputReader::ArduinoInputReader(int d_up, int d_down, int d_left, int d_right, int reset, int start, int b, int a) {
    this->d_up = d_up;
    this->d_down = d_down;
    this->d_left = d_left;
    this->d_right = d_right;
    this->reset = reset;
    this->start = start;
    this->b = b;
    this->a = a;

    pinMode(d_up, INPUT);
    pinMode(d_down, INPUT);
    pinMode(d_left, INPUT);
    pinMode(d_right, INPUT);
    pinMode(reset, INPUT);
    pinMode(start, INPUT);
    pinMode(b, INPUT);
    pinMode(a, INPUT);
}

void ArduinoInputReader::read_input(InputState *input_state) {
    if(digitalRead(this->d_up) == HIGH) {
        input_state->d_pad_direc = DIREC_UP;
    }

    if(digitalRead(this->d_down) == HIGH) {
        input_state->d_pad_direc = DIREC_DOWN;
    }

    if(digitalRead(this->d_left) == HIGH) {
        input_state->d_pad_direc = DIREC_LEFT;
    }

    if(digitalRead(this->d_right) == HIGH) {
        input_state->d_pad_direc = DIREC_RIGHT;
    }

    input_state->reset = digitalRead(this->reset) == HIGH ? BTN_DOWN : BTN_UP;

    input_state->start = digitalRead(this->start) == HIGH ? BTN_DOWN : BTN_UP;

    input_state->b = digitalRead(this->b) == HIGH ? BTN_DOWN : BTN_UP;

    input_state->a = digitalRead(this->a) == HIGH ? BTN_DOWN : BTN_UP;
}
