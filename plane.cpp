#include "plane.h"

#include <cstdio>
#include <iostream>
#include <numeric>

Plane::Plane() {
}

float Plane::isIntersection(const LightRay &ray) {
    return 1000.0f;
}

Light Plane::luminosite(const LightRay &ray, const World &world) const {
    if (ray.direction.X() > 0 && ray.direction.Y() > 0) return .33f;
    if (ray.direction.X() > 0 && ray.direction.Y() <= 0) return .25f;
    if (ray.direction.X() <= 0 && ray.direction.Y() > 0) return .5f;
    return .66f;
}


