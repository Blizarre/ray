#ifndef __SPHERE_0ff1
#define __SPHERE_0ff1

#include "element.h"
#include "world.h"
#include "vecteur3.h"
#include "Rayon.h"

class Sphere: public Element {
public:
    Sphere(const Position &pos, float diam);

    virtual float isIntersection(const Rayon & rayon);
    virtual Light luminosite(const Rayon & rayon,const World & world) const;

    void  deplacer(const Direction &d);

private:
	mutable Rayon lastRay;
    Position position;
    Position light;
    float radius2; // Rayon * Rayon
};


#endif
