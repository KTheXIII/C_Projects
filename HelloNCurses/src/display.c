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

#include <locale.h>
#include <ncurses.h>
#include <stdint.h>

struct Display {
    WINDOW *window;
    int32_t width;
    int32_t height;

    // display buffer
    Sprite *buffer;
};

Display display;
bool initialized = false;

Display *display_construct() {
    if (initialized) return &display;

    setlocale(LC_ALL, "");

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

int32_t display_getWidth() {
    if (!initialized) return 0;
    return display.width;
}
int32_t display_getHeight() {
    if (!initialized) return 0;
    return display.height;
}

void display_setInputTimeout(const int32_t timeout) { timeout(timeout); }
void display_setNoInputTimeout() { display_setInputTimeout(0); }
void display_setShowCursor(int8_t enable) { curs_set(enable); }

int32_t display_getInput() { return getch(); }

void display_clear() {
    for (int32_t i = 0; i < display.height; i++) {
        for (int32_t j = 0; j < display.width; j++) {
            sprite_setData(display.buffer, j, i, ' ');
            sprite_setColor(display.buffer, j, i, 0);
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

void display_draw(Sprite *sprite, int32_t x, int32_t y) {
    const int32_t width = sprite_getWidth(sprite);
    const int32_t height = sprite_getWidth(sprite);

    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            sprite_setColor(display.buffer, j + x, i + y,
                            sprite_getColor(sprite, j, i));
            sprite_setData(display.buffer, j + x, i + y,
                           sprite_getData(sprite, j, i));
        }
    }
}

void display_show() {
    for (int32_t i = 0; i < display.height; i++) {
        for (int32_t j = 0; j < display.width; j++) {
            int16_t colorID = sprite_getColor(display.buffer, j, i);
            attron(COLOR_PAIR(colorID));
            move(i, j);
            addch(sprite_getData(display.buffer, j, i));
            attroff(COLOR_PAIR(colorID));
        }
    }

    refresh();
}
