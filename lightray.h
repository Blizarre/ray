#pragma once

#include "vecteur3.h"

class LightRay {
public:
    LightRay(const Position& origine, const Direction &direction);
    LightRay();
    void update(const LightRay &ray);

    Position origine;
    Direction direction;
    Position intersection;
    float distance;
    int depth;
};
