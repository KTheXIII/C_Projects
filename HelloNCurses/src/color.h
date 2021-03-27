#ifndef __COLOR_H_
#define __COLOR_H_

#include <stdint.h>

#define COLOR_INIT_FAILED 0x01
#define COLOR_NO_COLOR 0x02

// clang-format off
enum DEFAULT_COLOR {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};
// clang-format on

typedef struct Color {
    int16_t id;
    int32_t value;
} Color;

void color_default();
int8_t color_init();

void color_initHEXColor(int16_t id, uint32_t color);
void color_initRGBColor(int16_t id, int16_t red, int16_t green, int16_t blue);
void color_initPair(int16_t id, int16_t fgColorID, int16_t bgColorID);

#endif