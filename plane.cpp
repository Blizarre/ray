#include "plane.h"

#include <cstdio>
#include <iostream>
#include <numeric>

Plane::Plane() {
}

float Plane::isIntersection(const Rayon &rayon) {
    return 1000.0f;
}

Light Plane::luminosite(const Rayon &rayon, const World &world) const {
    if (rayon.direction.X() > 0 && rayon.direction.Y() > 0) return .33f;
    if (rayon.direction.X() > 0 && rayon.direction.Y() <= 0) return .25f;
    if (rayon.direction.X() <= 0 && rayon.direction.Y() > 0) return .5f;
    return .66f;
}


