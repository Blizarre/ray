#ifndef __ELEMENT_0ff0
#define __ELEMENT_0ff0

#include"vecteur3.h"
#include <list>
#include <vector>

typedef Vecteur3<float> Vecteur;

struct Rayon {
    Rayon(const Vecteur &origine, const Vecteur &direction);
    void update(const Rayon &rayon);

    const Vecteur &origine;
    const Vecteur &direction;
    Vecteur intersection;
    float distance;
    int depth;
};

struct World;

struct Element {
    virtual bool  isIntersection(Rayon &rayon) const =0;
    virtual float luminosite(const Rayon &rayon, const World &world) const =0;
};

struct World {
    typedef std::list<Element*> Elements;
    float rayTracing(Rayon &rayon, const Element *from) const;

    ~World();

    Elements elements;
};

#endif
