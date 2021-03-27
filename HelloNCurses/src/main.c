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
#include <math.h>
#include <stdlib.h>

#include "display.h"
#include "sprite.h"
#include "color.h"

#define REFRESH_DELAY 50000L

int main(int argc, char const *argv[]) {
    Display *display = display_construct();
    int32_t displayWidth = display_getWidth();
    int32_t displayHeight = display_getHeight();

    color_default();
    color_init();
    // color_initColor(100, 1000, 0, 0);
    color_initHEXColor(100, 0x7CEA9C);
    color_initHEXColor(101, 0x55D6BE);
    color_initHEXColor(102, 0x2E5EAA);
    color_initHEXColor(103, 0x5B4E77);
    color_initHEXColor(104, 0x593959);
    color_initHEXColor(105, 0xF49097);
    color_initHEXColor(106, 0xDFB2F4);
    color_initHEXColor(107, 0xF5E960);
    color_initPair(100, 100, -1);
    color_initPair(101, 101, -1);
    color_initPair(102, 102, -1);
    color_initPair(103, 103, -1);
    color_initPair(104, 104, -1);
    color_initPair(105, 105, -1);
    color_initPair(106, 106, -1);
    color_initPair(107, 107, -1);

    float x = 0.0f, y = 0.0f;
    float xdir = 1.0f, ydir = 1.0f;
    float speed = 0.5f;

    int32_t dvdWidth = 5;
    int32_t dvdHeight = 1;
    Sprite *dvdSprite = sprite_construct(5, 1);
    sprite_setText(dvdSprite, "D V D", 0, 0, 100);

    char textBuffer[72];
    Sprite *textSprite = sprite_construct(72, 1);

    int8_t isRunning = 0x01;
    display_setNoInputTimeout();
    display_setShowCursor(0);

    int8_t overlay = 0x01;

    while (isRunning) {
        int32_t input = display_getInput();
        if (input == 'q') isRunning = 0x00;
        if (input == 'h') overlay = !overlay;

        x += speed * xdir;
        y += speed * ydir;

        if (x < 0 || x + dvdWidth > displayWidth) {
            sprite_setFillColor(dvdSprite, 100 + rand() % 8);
            xdir = -xdir;
        }
        if (y < 0 || y + dvdHeight > displayHeight) {
            sprite_setFillColor(dvdSprite, 100 + rand() % 8);
            ydir = -ydir;
        }

        display_clear();

        display_draw(dvdSprite, roundf(x), roundf(y));

        if (overlay) {
            display_print("Press \'q\' to quit\n'h' to hide overlay", 0, 0);
        }

        display_show();

        usleep(REFRESH_DELAY);
    }

    display_destructor();
    sprite_destructor(dvdSprite);
    return 0;
}
