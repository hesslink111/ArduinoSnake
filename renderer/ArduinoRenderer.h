//
// Created by Will Pease on 11/26/17.
//

#ifndef ARDUINO_SNAKE_ARDUINORENDERER_H
#define ARDUINO_SNAKE_ARDUINORENDERER_H


#include "Renderer.h"

class ArduinoRenderer : public Renderer {
private:
    // Adafruit_SSD1306 *screen;
public:
    ArduinoRenderer();
    void render(BoardState *board_state) override;
    void render_diffs(std::vector<DiffDescription *> *diffs);
};


#endif //ARDUINO_SNAKE_ARDUINORENDERER_H
