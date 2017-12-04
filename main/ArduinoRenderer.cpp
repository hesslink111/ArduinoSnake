//
// Created by Will Pease on 11/26/17.
//

#include "ArduinoRenderer.h"

#define BLUE_OFFSET 16

ArduinoRenderer::ArduinoRenderer() {
    screen = new Adafruit_SSD1306(4);
    screen->begin(SSD1306_SWITCHCAPVCC, 0x3C);
    screen->clearDisplay();
    screen->display();
}

void ArduinoRenderer::render(BoardState *board_state) {
    screen->clearDisplay();
    for(int y=0; y<10; y++) {
        for(int x=0; x<10; x++) {
            char board_char = (*board_state)[y][x];
            int color = board_char == ' ' ? BLACK : WHITE;
            screen->drawPixel(2*x, BLUE_OFFSET + 2*y, color);
        }
    }
    screen->display();
}

void ArduinoRenderer::render_diffs(std::vector<DiffDescription *> *diffs) {
    for(int i=0; i<diffs->size(); i++) {
        DiffDescription *diff = (*diffs)[i];
        int color = diff->val == ' ' ? BLACK : WHITE;
        screen->drawPixel(2 * diff->pos_x, BLUE_OFFSET + 2 * diff->pos_y, color);
    }
    screen->display();
}
