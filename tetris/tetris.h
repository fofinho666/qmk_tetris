#include <stdbool.h>
#include "xorshift.h"
#include "screen.h"

struct Tetris {
  uint8_t blocks[40][10];
  uint8_t cur;
  uint8_t curx;
  uint8_t cury;
  uint8_t rot;
  uint8_t next;
  uint8_t nextrot;
  uint8_t gamestate;
  uint16_t lasttime;
  uint16_t score;
  uint8_t counter;
  uint16_t speed;
  bool shadow;
  uint16_t shadow_time;
  Xorshift xorshift;
  bool initialized;
};
typedef struct Tetris Tetris;

extern void tetris_init(Tetris *tetris);
extern void tetris_update(Tetris *tetris);
extern void tetris_render(Tetris *tetris, Screen* screen);

// dir:
//   0: Left
//   1: Right
//   2: Down
extern void tetris_move(Tetris *tetris, int dir);

// cw:
//   0: Clockwise
//   1: Counterclockwise
extern void tetris_rotate(Tetris *tetris, int cw);
