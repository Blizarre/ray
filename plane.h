#pragma once

#include "element.h"
#include "world.h"

class Plane : public Element {
public:
    Plane();

    virtual float isIntersection(const LightRay &ray);
    virtual Light luminosite(const LightRay &ray, const World &world) const;

protected:
    LightRay lastIntersection;
};
