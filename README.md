# QMK Tetris
Tetris for keyboards that use the [QMK firmware](https://github.com/qmk/qmk_firmware) and a 128x32 OLED SSD1306 display.

The original code is from [melpon](https://github.com/melpon/qmk_games). I just made it work with the [OLED driver](https://docs.qmk.fm/#/feature_oled_driver?id=oled-driver) and tweak the game a bit to my liking.

![](gif/demo.gif)

## Setup

This game is meant to be added to a keyboard with a **128x32** OLED display and **0 degrees of rotation**.


Do the following steps to add the game to your keyboard:
- Copy the repo folder `tetris/` into the the root of the QMK keyboard folder `qmk_firmware/keyboards/<your_keyboard>/`
- On your **rules.mk** file at `qmk_firmware/keyboards/<your_keyboard>/keymaps/<your_keymap>/`, add the source for the code:
```
SRC += tetris/screen.c \
       tetris/xorshift.c \
       tetris/tetris.c
```
- After this you need to modify some functions on your **keymap.c** file that is also at `qmk_firmware/keyboards/<your_keyboard>/keymaps/<your_keymap>/`

  - include tetris at the beginning of the file:
  ```c
  #include "games/tetris.h"
  #include "games/screen.h"

  Tetris kb_tetris;
  ```

  - create the render function and add it to the `oled_task_user` function
  ```c
  void tetris_run(void){
    Screen tetris_screen;
    screen_clear(&tetris_screen);

    tetris_update(&kb_tetris);
    tetris_render(&kb_tetris, &tetris_screen);

    oled_write_raw((char*) tetris_screen.buffer, sizeof(tetris_screen.buffer));
  }

  ...

  void oled_task_user(void) {
    // ... your code and conditions
    tetris_run();
    // ... the rest of your code and conditions
  }
  ```


  - create the input function and add it to the `process_record_user` function
  ```c
  void tetris_play(uint16_t keycode) {
    switch (keycode) {
      case KC_LEFT:
        tetris_move(&kb_tetris, 0); // left key to go left
        break;
      case KC_RGHT:
        tetris_move(&kb_tetris, 1); // right key to go right
        break;
      case KC_DOWN:
        tetris_rotate(&kb_tetris, 0); // up key to rotate clockwise
        break;
      case KC_UP:
        tetris_rotate(&kb_tetris, 1); // up key to rotate counterclockwise
        break;
      case KC_SPC:
        tetris_move(&kb_tetris, 2); // space to drop the block
        break;
    }
  }

  ...

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      // ... your code and conditions
      tetris_play(keycode);
      return false;
      // ... the rest of your code and conditions
  }
  ```

enjoy :)

