#pragma once

#include "vecteur3.h"

class LightRay {
public:
    LightRay(const Position& origin, const Direction &direction);
    LightRay();
    void update(const LightRay &ray);

    Position origin;
    Direction direction;
    Position intersection;
    float distance;
    int depth;
};
