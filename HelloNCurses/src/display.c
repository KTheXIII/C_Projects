/**
 * @file    display.c
 * @author  KTheXIII (pratchaya.k.git@gmail.com)
 * @brief   display.h implementations
 * @version 0.1
 * @date    2021-03-23
 *
 * @copyright Copyright (c) 2021
 */

#include "display.h"

#include <ncurses.h>
#include <stdint.h>

struct Display {
    WINDOW *window;
    int32_t width;
    int32_t height;

    Sprite *buffer;
};

Display display;
bool initialized = false;

Display *display_construct() {
    if (initialized) return &display;

    display.window = initscr();
    getmaxyx(stdscr, display.height, display.width);

    display.buffer = sprite_construct(display.width, display.height);

    initialized = true;
    return &display;
}

Display *display_get() {
    if (!initialized) return NULL;
    return &display;
}

void display_destructor() {
    endwin();
    sprite_destructor(display.buffer);
}

void display_setInputTimeout(const int32_t timeout) { timeout(timeout); }
void display_setNoInputTimeout() { display_setInputTimeout(0); }
void display_setShowCursor(int8_t enable) { curs_set(enable); }

int32_t display_getInput() { return getch(); }

void display_clear() {
    for (int32_t i = 0; i < display.height; i++) {
        for (int32_t j = 0; j < display.width; j++) {
            sprite_setData(display.buffer, j, i, ' ');
        }
    }
}

void display_print(const char *text, int32_t x, int32_t y) {
    int32_t row = y;
    int32_t col = x;
    const char *textPtr = text;

    while (*textPtr) {
        sprite_setData(display.buffer, col, row, *textPtr);
        if (*textPtr == '\n') {
            col = x;
            row++;
        } else {
            col++;
        }
        textPtr++;
    }
}

void display_draw(const Sprite *sprite, int32_t x, int32_t y) {
    const int32_t width = sprite_getWidth(sprite);
    const int32_t height = sprite_getWidth(sprite);

    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            sprite_setData(display.buffer, j + x, i + y,
                           sprite_getData(sprite, j, i));
        }
    }
}

void display_show() {
    for (int32_t i = 0; i < display.height; i++) {
        for (int32_t j = 0; j < display.width; j++) {
            move(i, j);
            addch(sprite_getData(display.buffer, j, i));
        }
    }

    refresh();
}
