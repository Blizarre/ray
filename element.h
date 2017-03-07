#pragma once

#include "light.h"
#include "lightray.h"
#include "world.h"

// Why should I need to declare World, since the header world?h is alreay included ?
// Maybe because there's a reference to World in the the definition of Element and vice versa
class World;

class Element {
public:
    virtual float isIntersection(const LightRay & ray) = 0;
    virtual Light luminosite(const LightRay &, const World &) const = 0;

    virtual ~Element() {
    };
};
