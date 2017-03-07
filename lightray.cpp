#include "lightray.h"

LightRay::LightRay(const Position &origin, const Direction &direction) : origin(origin), direction(direction), intersection(0, 0, 0), distance(0) {
}

LightRay::LightRay() {
}

void LightRay::update(const LightRay &ray) {
    intersection = ray.intersection;
    distance = ray.distance;
}
