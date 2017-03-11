#pragma once

#include "element.h"
#include "world.h"
#include "vecteur3.h"
#include "lightray.h"
#include "material.h"

class Sphere : public Element {
public:
    Sphere(const Position &pos, float diam, Material mat);

    virtual float isIntersection(const LightRay & ray);
    virtual Light luminosity(const LightRay & ray, const World & world) const;

    void translate(const Direction &d);

private:
    mutable LightRay lastRay;
    Position position;
    float radius2; // ray * ray
    Material mat;
};
