#include <stdio.h>
#include <time.h>

#include "Terminal.h"

int main(int argc, char const *argv[]) {
    int32_t spriteWidth = 10;
    int32_t spriteHeight = 5;
    float x = 0.f, y = 0.f;
    float xDir = 1.f, yDir = 1.f;
    float speed = 0.01f;

    Sprite *sprite = TL_SpriteConstruct(spriteWidth, spriteHeight);
    for (int32_t i = 0; i < TL_SpriteGetHeight(sprite); i++) {
        for (int32_t j = 0; j < TL_SpriteGetWidth(sprite); j++) {
            TL_SpriteSetData(sprite, j, i, L'▇');
        }
    }

    TL_DisplayConstruct(TL_DONT_CARE, TL_DONT_CARE);

    int32_t displayWidth = TL_DisplayGetWidth();
    int32_t displayHeight = TL_DisplayGetHeight();

    wchar_t text[256] = L"Hello, World!";

    while (1) {
        // Update

        x += speed * xDir;
        y += speed * yDir;

        if (x < 0 || x + spriteWidth > displayWidth) {
            xDir = -xDir;
        }
        if (y < 0 || y + spriteHeight > displayHeight) {
            yDir = -yDir;
        }

        // Draw
        TL_DisplayClear();

        TL_DisplayDraw(sprite, (int32_t)x, (int32_t)y);
        TL_DisplayPrint(text, 0, 0);

        TL_DisplayShow();
    }

    TL_DisplayDestruct();
    TL_SpriteDestruct(sprite);
    return 0;
}
