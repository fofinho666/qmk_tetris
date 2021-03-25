#include "screen.h"
#include <string.h>

void screen_clear(Screen *screen) { memset(screen->buffer, 0, sizeof(screen->buffer)); }

void screen_draw_pixel(Screen *screen, uint8_t x, uint8_t y) {
  uint16_t index = (TETRIS_BUFFER_SIZE - 1) - (y + (x / 8) * TETRIS_DISPLAY_WIDTH);
  uint8_t  data  = screen->buffer[index];

  data |= (1 << (7 - x % 8));
  screen->buffer[index] = data;
}

void screen_draw_rect(Screen *screen, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
  uint8_t x2 = x + w;
  uint8_t y2 = y + h;

  for (uint8_t x1 = x; x1 < x2; x1++) {
    for (uint8_t y1 = y; y1 < y2; y1++) {
      screen_draw_pixel(screen, x1, y1);
    }
  }
}
