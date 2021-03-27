#include "color.h"

#include <ncurses.h>

int8_t color_init() {
    start_color();

    if (!has_colors() || !can_change_color()) return COLOR_NO_COLOR;
}

void color_default() { use_default_colors(); }

void color_initHEXColor(int16_t id, uint32_t color) {
    int16_t red = (int16_t)((float)((color & 0xFF0000) >> 16) / 255.0 * 1000.0);
    int16_t green =
        (int16_t)((float)((color & 0x00FF00) >> 8) / 255.0 * 1000.0);
    int16_t blue = (int16_t)((float)((color & 0x0000FF) >> 0) / 255.0 * 1000.0);
    color_initRGBColor(id, red, green, blue);
}
void color_initRGBColor(int16_t id, int16_t red, int16_t green, int16_t blue) {
    init_color(id, red, green, blue);
}
void color_initPair(int16_t id, int16_t fgColorID, int16_t bgColorID) {
    init_pair(id, fgColorID, bgColorID);
}
