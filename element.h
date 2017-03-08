#pragma once

#include "light.h"
#include "lightray.h"
#include "world.h"

// to resolve circular dependency ELement <-> World 
class World;

class Element {
public:
    virtual float isIntersection(const LightRay & ray) = 0;
    virtual Light luminosity(const LightRay &, const World &) const = 0;

    virtual ~Element() {
    };
};
