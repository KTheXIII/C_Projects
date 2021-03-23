#include "display.h"

#include <stdlib.h>

WINDOW *window = NULL;
DISPLAY data;

DISPLAY *display_init() {
    // Initialize ncurses
    window = initscr();
    getmaxyx(stdscr, data.height, data.width);

    data.buffer = malloc(sizeof(int32_t) * data.width * data.height);

    display_clear();

    curs_set(0);  // disable cursor

    return &data;
}

DISPLAY *display_getbuffer() { return &data; }

WINDOW *display_getwindow() { return window; }

void display_clear() {
    for (int32_t i = 0; i < data.height; i++) {
        for (int32_t j = 0; j < data.width; j++) {
            data.buffer[i * data.width + j] = ' ';
        }
    }
}

void display_set(int32_t row, int32_t col, int32_t value) {
    if (row > -1 && row < data.height && col > -1 && col < data.width) {
        data.buffer[row * data.width + col] = value;
    }
}

void display_show() {
    for (int32_t i = 0; i < data.height; i++) {
        for (int32_t j = 0; j < data.width; j++) {
            int32_t value = data.buffer[i * data.width + j];
            mvaddch(i, j, value);
        }
    }

    refresh();
}

void display_cleanup() {
    free(data.buffer);

    // Cleanup ncurses
    endwin();
}