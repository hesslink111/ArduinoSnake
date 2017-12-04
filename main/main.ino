#include "ArduinoGame.h"
#include "Timer.h"

ArduinoGame *arduino_game;
Timer *timer;

void read_input() {
    Serial.println("Reading input");
    arduino_game->read_input();
}

void move_and_render() {
    Serial.println("Moving and rendering");
    arduino_game->move_and_render();
}

void setup() {
    Serial.begin(115200);

    arduino_game = new ArduinoGame();
    arduino_game->render_initial();

    timer = new Timer();

    timer->set_interval(read_input, 66);
    timer->set_interval(move_and_render, 500);
}

void loop () {
    timer->run_next();
}