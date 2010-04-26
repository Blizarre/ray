#ifndef __PLANE_H__
#define __PLANE_H__

#include "element.h"

class Plane: public Element {
public:
    Plane();

    bool  isIntersection(Rayon &rayon) const;
    float luminosite(const Rayon &rayon,const World &world) const;
};

#endif

