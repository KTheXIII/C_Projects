/**
 * @file Sprite.c
 * @author Pratchaya Khansomboon (pratchaya.k.git@gmail.com)
 * @brief Sprite implemenation for drawing.
 * @version 0.1
 * @date 2021-03-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "Terminal/Sprite.h"

#include <stdlib.h>

struct Sprite {
    int32_t width;
    int32_t height;

    // data and color buffer
    wchar_t *dataBuffer;
};

Sprite *TL_SpriteConstruct(int32_t width, int32_t height) {
    Sprite *sprite = malloc(sizeof(Sprite));
    if (sprite == NULL) return NULL;

    sprite->width = width;
    sprite->height = height;
    sprite->dataBuffer = malloc(sizeof(wchar_t) * width * height);

    if (sprite->dataBuffer == NULL) {
        free(sprite);
        return NULL;
    }
    return sprite;
}
void TL_SpriteDestruct(Sprite *sprite) {
    free(sprite->dataBuffer);
    free(sprite);
}

wchar_t *TL_SpriteGetBuffer(Sprite *sprite) { return sprite->dataBuffer; }

void TL_SpriteSetText(Sprite *sprite, const wchar_t *text, uint32_t x,
                      int32_t y, int16_t color) {
    int32_t row = y;
    int32_t col = x;
    int32_t index = 0;
    while (text[index]) {
        TL_SpriteSetData(sprite, col, row, text[index]);
        col++;

        if (text[index] == '\n') {
            col = x;
            row++;
        }
        index++;
    }
}
void TL_SpriteSetData(Sprite *sprite, int32_t x, int32_t y, wchar_t data) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height) {
        const int32_t index = y * sprite->width + x;
        sprite->dataBuffer[index] = data;
    }
}
wchar_t TL_SpriteGetData(Sprite *sprite, int32_t x, int32_t y) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height)
        return sprite->dataBuffer[y * sprite->width + x];
    return ' ';
}

int32_t TL_SpriteGetWidth(Sprite *sprite) { return sprite->width; }
int32_t TL_SpriteGetHeight(Sprite *sprite) { return sprite->height; }