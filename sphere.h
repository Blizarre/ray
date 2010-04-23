#ifndef __SPHERE_0ff1
#define __SPHERE_0ff1

#include "element.h"

class Sphere: public Element {
public:
    Sphere(const Vecteur &pos, float diam);

    bool  isIntersection(Rayon &rayon) const;
    float luminosite(const Rayon &rayon,const World &world) const;

    void  deplacer(const Vecteur &d);

private:
    Vecteur position;
    Vecteur light;
    float radius2; // Rayon * Rayon
};


#endif
