#include "lightray.h"

LightRay::LightRay(const Position &origine, const Direction &direction) : origine(origine), direction(direction), intersection(0, 0, 0), distance(0) {
}

LightRay::LightRay() {
}

void LightRay::update(const LightRay &ray) {
    intersection = ray.intersection;
    distance = ray.distance;
}
