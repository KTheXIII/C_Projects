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

void sprite_setData(Sprite *sprite, int32_t x, int32_t y, uint32_t data);
uint32_t sprite_getData(const Sprite *sprite, int32_t x, int32_t y);

int32_t sprite_getWidth(const Sprite *sprite);
int32_t sprite_getHeight(const Sprite *sprite);
#endif