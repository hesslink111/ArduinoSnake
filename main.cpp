#include <iostream>
#include "ArduinoGame.h"
#include "timer/Timer.h"

int main() {

    ArduinoGame *arduino_game = new ArduinoGame();
    arduino_game->render_initial();

    Timer *timer = new Timer();

    timer->set_timeout(std::bind(&ArduinoGame::read_input, arduino_game), 66);
    timer->set_timeout(std::bind(&ArduinoGame::move_and_render, arduino_game), 500);

    timer->set_timeout([](){std::cout << "Hello world!2" << std::endl;}, 2000);
    timer->set_timeout([](){std::cout << "Hello world!0" << std::endl;}, 500);
    timer->set_timeout([](){std::cout << "Hello world!1" << std::endl;}, 1500);

    while(true) {
        timer->run_next();
    }

    return 0;
}