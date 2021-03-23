#include <ncurses.h>
#include <stdint.h>

#include "display.h"

int main(int argc, char const *argv[]) {
    DISPLAY *display = display_init();

    for (int32_t i = 0; i < display->height; i++) {
        for (int32_t j = 0; j < display->width; j++) {
            if (i == 0 || i == display->height - 1 || j == 0 ||
                j == display->width - 1)
                display_set(i, j, '*');
        }
    }

    display_show();

    getch();

    display_cleanup();

    return 0;
}
