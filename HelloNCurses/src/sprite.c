#include "sprite.h"

#include <stdlib.h>

struct Sprite {
    int32_t width;
    int32_t height;

    // data and color buffer
    uint32_t *dataBuffer;
    int16_t *colorBuffer;
};

struct Sprite *sprite_construct(int32_t width, int32_t height) {
    Sprite *sprite = (Sprite *)malloc(sizeof(Sprite));
    sprite->width = width;
    sprite->height = height;
    sprite->dataBuffer = malloc(sizeof(uint32_t) * width * height);
    sprite->colorBuffer = malloc(sizeof(int16_t) * width * height);
    return sprite;
}

void sprite_destructor(Sprite *sprite) {
    free(sprite->dataBuffer);
    free(sprite->colorBuffer);
    free(sprite);
}
void sprite_setText(Sprite *sprite, const char *text, int32_t x, int32_t y,
                    int16_t color) {
    int32_t row = y;
    int32_t col = x;
    int32_t index = 0;
    while (text[index]) {
        sprite_setData(sprite, col, row, text[index]);
        sprite_setColor(sprite, col, row, color);
        col++;

        if (text[index] == '\n') {
            col = x;
            row++;
        }
        index++;
    }
}
void sprite_setFillColor(Sprite *sprite, int16_t color) {
    for (int32_t i = 0; i < sprite->height; i++) {
        for (int32_t j = 0; j < sprite->width; j++) {
            sprite_setColor(sprite, j, i, color);
        }
    }
}
void sprite_setColor(Sprite *sprite, int32_t x, int32_t y, int16_t color) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height) {
        const int32_t index = y * sprite->width + x;
        sprite->colorBuffer[index] = color;
    }
}
void sprite_setData(Sprite *sprite, int32_t x, int32_t y, uint32_t data) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height) {
        const int32_t index = y * sprite->width + x;
        sprite->dataBuffer[index] = data;
    }
}
uint32_t sprite_getData(Sprite *sprite, int32_t x, int32_t y) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height)
        return sprite->dataBuffer[y * sprite->width + x];
    return ' ';
}

int16_t sprite_getColor(Sprite *sprite, int32_t x, int32_t y) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height)
        return sprite->colorBuffer[y * sprite->width + x];
    return 0;
}

int32_t sprite_getWidth(Sprite *sprite) { return sprite->width; }
int32_t sprite_getHeight(Sprite *sprite) { return sprite->height; }