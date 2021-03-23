/**
 * @file    display.h
 * @author  KTheXIII (pratchaya.k.git@gmail.com)
 * @brief   Initialize the display and stores its propery
 * @version 0.1
 * @date    2021-03-23
 *
 * @copyright Copyright (c) 2021
 */

#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#include <wchar.h>
#include <stdint.h>
#include <ncurses.h>

/**
 * Display data container
 */
typedef struct {
    int32_t width;
    int32_t height;
    int32_t *buffer;
} DISPLAY;

DISPLAY *display_init();

DISPLAY *display_getbuffer();

WINDOW *display_getwindow();

void display_clear();

void display_set(int32_t row, int32_t col, int32_t value);

void display_show();

void display_cleanup();

#endif