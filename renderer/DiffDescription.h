//
// Created by Will Pease on 11/26/17.
//

#ifndef ARDUINO_SNAKE_DIFFDESCRIPTION_H
#define ARDUINO_SNAKE_DIFFDESCRIPTION_H


class DiffDescription {
public:
    int pos_x;
    int pos_y;
    char val;
    DiffDescription(int pos_x, int pos_y, char val);
};


#endif //ARDUINO_SNAKE_DIFFDESCRIPTION_H
