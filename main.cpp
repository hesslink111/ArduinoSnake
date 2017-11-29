#include <iostream>
#include "ArduinoGame.h"
#include "timer/Timer.h"

int main() {

    ArduinoGame *arduino_game = new ArduinoGame();
    arduino_game->render_initial();

    Timer *timer = new Timer();

    timer->set_timeout(std::bind(&ArduinoGame::read_input, arduino_game), 66);
    timer->set_timeout(std::bind(&ArduinoGame::move_and_render, arduino_game), 500);

    while(true) {
        timer->run_next();
    }

    return 0;
}