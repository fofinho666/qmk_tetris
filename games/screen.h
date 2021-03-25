#ifndef SCREEN_H
#define SCREEN_H

#define TETRIS_BUFFER_SIZE 512
#define TETRIS_DISPLAY_WIDTH 128

struct Screen {
  uint8_t buffer[TETRIS_BUFFER_SIZE];
};
typedef struct Screen Screen;

void screen_clear(Screen* screen);

void screen_draw_rect(Screen* screen, uint8_t x, uint8_t y, uint8_t w, uint8_t h);

#endif  // SCREEN_H
