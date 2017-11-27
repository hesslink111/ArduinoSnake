//
// Created by Will Pease on 11/26/17.
//

#include "ArduinoRenderer.h"

ArduinoRenderer::ArduinoRenderer() {
    // screen.begin();
    // screen.clearDisplay();
}

void ArduinoRenderer::render(BoardState *board_state) {
    // screen.clearDisplay()
    for(int y=0; y<10; y++) {
        for(int x=0; x<10; x++) {
            char board_char = (*board_state)[y][x];
            // int color = board_char == 0 ? BLACK : WHITE;
            // screen->drawPixel(x, y, color);
        }
    }
}

void ArduinoRenderer::render_diffs(std::vector<DiffDescription *> *diffs) {

}
