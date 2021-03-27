/**
 * @file Sprite.h
 * @author Pratchaya Khansomboon (pratchaya.k.git@gmail.com)
 * @brief  Sprite data interface
 * @version 0.1
 * @date 2021-03-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __SPRITE_H_
#define __SPRITE_H_

#include <stdint.h>
#include <wchar.h>

typedef struct Sprite Sprite;

Sprite *TL_SpriteConstruct(int32_t width, int32_t height);
void TL_SpriteDestruct(Sprite *sprite);

wchar_t *TL_SpriteGetBuffer(Sprite *sprite);

void TL_SpriteSetText(Sprite *sprite, const wchar_t *text, uint32_t x,
                      int32_t y, int16_t color);
void TL_SpriteSetData(Sprite *sprite, int32_t x, int32_t y, wchar_t data);
wchar_t TL_SpriteGetData(Sprite *sprite, int32_t x, int32_t y);

int32_t TL_SpriteGetWidth(Sprite *sprite);
int32_t TL_SpriteGetHeight(Sprite *sprite);

#endif
