/**
 * @file Display.c
 * @author Pratchaya Khansomboon (pratchaya.k.git@gmail.com)
 * @brief The display implemenation for different platform.
 * @version 0.1
 * @date 2021-03-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "Terminal/Display.h"

struct Display {
    int32_t width;
    int32_t height;

    Sprite *buffer;
};

Display display;

// Platform specific code

#ifdef __UNIX_

#include <ncurses.h>
#include <wchar.h>

Display *TL_DisplayConstruct(int32_t width, int32_t height) {
    display.width = width;
    display.height = height;

    display.buffer = initscr();
    // getmaxyx(stdscr, display.height, display.width);

    display.buffer = TL_SpriteConstruct(display.width, display.height);

    return &display;
}

void TL_DisplayShow() {
    for (int32_t i = 0; i < display.height; i++) {
        for (int32_t j = 0; j < display.width; j++) {
            move(i, j);
            addch(TL_SpriteGetData(display.buffer, j, i));
        }
    }

    refresh();
}

#elif _WIN32

#include <Windows.h>

HANDLE console;
DWORD bytesWritten;
COORD coord = {0, 0};

Display *TL_DisplayConstruct(int32_t width, int32_t height) {
    display.width = width;
    display.height = height;
    display.buffer = TL_SpriteConstruct(display.width, display.height);

    console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
                                        CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(console);
    bytesWritten = 0;

    return &display;
}

void TL_DisplayShow() {
    const int32_t width = TL_SpriteGetWidth(display.buffer);
    const int32_t height = TL_SpriteGetHeight(display.buffer);
    WriteConsoleOutputCharacterW(console, TL_SpriteGetBuffer(display.buffer),
                                 display.width * display.height, coord,
                                 &bytesWritten);
}

#endif

// Platform agnostic code

void TL_DisplayDestruct() {
    // free up the buffer
    TL_SpriteDestruct(display.buffer);
}

int32_t TL_DisplayGetWidth() { return display.width; }

int32_t TL_DisplayGetHeight() { return display.height; }

void TL_DisplayClear() {
    for (int32_t i = 0; i < display.height; i++) {
        for (int32_t j = 0; j < display.width; j++) {
            TL_SpriteSetData(display.buffer, j, i, L' ');
        }
    }
}
void TL_DisplayPrint(const wchar_t *text, int32_t x, int32_t y) {
    int32_t row = y;
    int32_t col = x;
    int32_t index = 0;

    while (text[index]) {
        TL_SpriteSetData(display.buffer, col, row, text[index]);
        col++;

        if (text[index] == '\n') {
            col = x;
            row++;
        }
        index++;

        if (index == INT32_MAX) return;
    }
}

void TL_DisplayDraw(Sprite *sprite, int32_t x, int32_t y) {
    const int32_t width = TL_SpriteGetWidth(sprite);
    const int32_t height = TL_SpriteGetHeight(sprite);

    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            TL_SpriteSetData(display.buffer, j + x, i + y,
                             TL_SpriteGetData(sprite, j, i));
        }
    }
}
