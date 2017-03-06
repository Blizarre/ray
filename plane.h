#ifndef __PLANE_H__
#define __PLANE_H__

#include "element.h"
#include "world.h"
class Plane: public Element {
public:
    Plane();

    virtual float isIntersection(const Rayon &rayon);
    virtual Light luminosite(const Rayon &rayon,const World &world) const;

protected:
	Rayon lastIntersection;
};

#endif

