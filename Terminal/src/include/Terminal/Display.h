/**
 * @file Display.h
 * @author Pratchaya Khansomboon (pratchaya.k.git@gmail.com)
 * @brief Handles all the display output and input
 * @version 0.1
 * @date 2021-03-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#include <stdint.h>
#include <wchar.h>

#include "Terminal/Sprite.h"

#define TL_DONT_CARE INT32_MIN

typedef struct Display Display;

Display *TL_DisplayConstruct(int32_t width, int32_t height);
void TL_DisplayDestruct();

int32_t TL_DisplayGetWidth();
int32_t TL_DisplayGetHeight();

void TL_DisplayClear();
void TL_DisplayPrint(const wchar_t *text, int32_t x, int32_t y);
void TL_DisplayDraw(Sprite *sprite, int32_t x, int32_t y);
void TL_DisplayShow();

void TL_NoInputTimeout();
void TL_ShowCursor(int8_t enable);
int32_t TL_GetInput();

#endif
