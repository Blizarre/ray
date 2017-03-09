#pragma once

#include "SDL.h"

class Pixel {
public:

    Pixel() {
        A = 0xff;
    }
    Uint8 B;
    Uint8 G;
    Uint8 R;

    Uint8 A;
};

void freeRenderer(Uint32 *myPixels);
void showImage(Uint32 *myPixels);

Uint32* InitVideo(int, int);

void setPixelValue(Uint32 *surface, int x, int y, Pixel pixel);

