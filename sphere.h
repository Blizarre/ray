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
    virtual Light luminosite(const LightRay & ray, const World & world) const;

    void deplacer(const Direction &d);

private:
    mutable LightRay lastRay;
    Position position;
    Position light;
    float radius2; // ray * ray
    Material mat;
};
