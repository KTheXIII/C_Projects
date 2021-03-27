/**
 * @file    main.c
 * @author  KTheXIII (pratchaya.k.git@gmail.com)
 * @brief   The main program for the HelloNCurses
 * @version 0.1
 * @date    2021-03-23
 *
 * @copyright Copyright (c) 2021
 */
#include <stdint.h>
#include <unistd.h>

#include "display.h"
#include "sprite.h"

#define REFRESH_DELAY 50000L

int main(int argc, char const *argv[]) {
    Display *display = display_construct();

    Sprite *sprite = sprite_construct(10, 5);
    for (int32_t i = 0; i < sprite_getHeight(sprite); i++) {
        for (int32_t j = 0; j < sprite_getWidth(sprite); j++) {
            sprite_setData(sprite, j, i, 'A');
        }
    }

    int8_t isRunning = 0x01;
    display_setNoInputTimeout();
    display_setShowCursor(0);

    while (isRunning) {
        int32_t input = display_getInput();
        if (input == 'q') isRunning = 0x00;

        display_clear();

        display_print("Hello, World!", 2, 1);

        display_draw(sprite, 20, 10);

        display_show();

        usleep(REFRESH_DELAY);
    }

    display_destructor();
    sprite_destructor(sprite);
    return 0;
}
