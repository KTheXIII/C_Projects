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

#include "sprite.h"
#include <stdint.h>

typedef struct Display Display;

Display *display_construct();

Display *display_get();

void display_destructor();

int32_t display_getWidth();
int32_t display_getHeight();

void display_setInputTimeout(const int32_t timeout);
void display_setNoInputTimeout();
void display_setShowCursor(int8_t enable);

int32_t display_getInput();

void display_clear();
void display_print(const char *text, int32_t x, int32_t y);
void display_draw(Sprite *sprite, int32_t x, int32_t y);
void display_show();

#endif
