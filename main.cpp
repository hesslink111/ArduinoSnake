#include <iostream>
#include "ArduinoGame.h"

int main() {

    ArduinoGame *arduino_game = new ArduinoGame();
    arduino_game->render_initial();

    // set_timeout(arduino_game->read_input, 66);
    // set_timeout(arduino_game->move_and_render, 500);

    return 0;
}