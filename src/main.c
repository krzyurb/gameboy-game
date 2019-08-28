#include <gb/gb.h>
#include <stdio.h>
#include "tiles.c"

void init(void);
void loop(void);

void main(void) {
  init();

  while(1) {
    loop();
  }
}

void init(void) {
  printf("Hello GameBoy!1\n");
  set_sprite_data(0, 2, Tiles);
  set_sprite_tile(0, 0);
  move_sprite(0, 50, 50);
  SHOW_SPRITES;
}

void loop(void) {
  unsigned char joy_pad_value = joypad();

  switch(joy_pad_value) {
    case J_RIGHT:
      scroll_sprite(0, 5, 0);
        set_sprite_tile(0, 1);
      delay(100);
    break;

    case J_LEFT:
      scroll_sprite(0, -5, 0);
      set_sprite_tile(0, 1);
      delay(100);
    break;

    case J_UP:
      scroll_sprite(0, 0, -5);
        set_sprite_tile(0, 1);
      delay(100);
    break;

    case J_DOWN:
      scroll_sprite(0, 0, 5);
      set_sprite_tile(0, 1);
      delay(100);
    break;

    default:
      set_sprite_tile(0, 0);
    break;
  }
}
