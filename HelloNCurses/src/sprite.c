#include "sprite.h"

#include <stdlib.h>

struct Sprite {
    int32_t width;
    int32_t height;

    // data buffer
    uint32_t *buffer;
};

struct Sprite *sprite_construct(int32_t width, int32_t height) {
    Sprite *sprite = malloc(sizeof(Sprite));
    sprite->width = width;
    sprite->height = height;
    sprite->buffer = malloc(sizeof(uint32_t) * width * height);
    return sprite;
}

void sprite_destructor(Sprite *sprite) {
    free(sprite->buffer);
    free(sprite);
}

void sprite_setData(Sprite *sprite, int32_t x, int32_t y, uint32_t data) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height) {
        const int32_t index = y * sprite->width + x;
        sprite->buffer[index] = data;
    }
}

uint32_t sprite_getData(const Sprite *sprite, int32_t x, int32_t y) {
    if (x > -1 && x < sprite->width && y > -1 && y < sprite->height)
        return sprite->buffer[y * sprite->width + x];
    return ' ';
}

int32_t sprite_getWidth(const Sprite *sprite) { return sprite->width; }

int32_t sprite_getHeight(const Sprite *sprite) { return sprite->height; }