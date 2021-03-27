/**
 * @file sprite.h
 * @author  KTheXIII (pratchaya.k.git@gmail.com)
 * @brief   Srpite
 * @version 0.1
 * @date 2021-03-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __SPRITE_H_
#define __SPRITE_H_

#include <stdint.h>

typedef struct Sprite Sprite;

Sprite *sprite_construct(int32_t width, int32_t height);
void sprite_destructor(Sprite *sprite);

void sprite_setText(Sprite *sprite, const char *text, int32_t x, int32_t y,
                    int16_t color);
void sprite_setFillColor(Sprite *sprite, int16_t color);
void sprite_setColor(Sprite *sprite, int32_t x, int32_t y, int16_t color);
void sprite_setData(Sprite *sprite, int32_t x, int32_t y, uint32_t data);
uint32_t sprite_getData(Sprite *sprite, int32_t x, int32_t y);
int16_t sprite_getColor(Sprite *sprite, int32_t x, int32_t y);

int32_t sprite_getWidth(Sprite *sprite);
int32_t sprite_getHeight(Sprite *sprite);
#endif