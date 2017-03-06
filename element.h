#ifndef __ELEMENT_0ff0
#define __ELEMENT_0ff0

#include "light.h"
#include "rayon.h"
#include "world.h"

// Why should I need to declare World, since the header world?h is alreay included ?
// Maybe because there's a reference to World in the the definition of Element and vice versa
class World;

class Element {
public:
    virtual float isIntersection(const Rayon & rayon) =0;
    virtual Light luminosite(const Rayon &, const World &) const =0;
};


#endif
