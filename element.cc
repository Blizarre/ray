#include "element.h"

#include <limits>

Rayon::Rayon(const Vecteur &origine, const Vecteur &direction) : origine(origine), direction(direction), intersection(0,0,0), distance(0) {}

void Rayon::update(const Rayon &rayon) {
    intersection = rayon.intersection;
    distance = rayon.distance;
}

float World::rayTracing(Rayon &rayon, const Element *from) const {
    const Element *elementMin = NULL;
    Rayon rayonMin(rayon);
    rayonMin.distance = std::numeric_limits<float>::max();

    for (Elements::const_iterator it=elements.begin(); it!=elements.end(); it++) {
        const Element *elem = *it;
        if (elem != from and elem->isIntersection(rayon) and rayon.distance < rayonMin.distance) {
            rayonMin.update(rayon);
            elementMin = elem;
        }
    }

    if (elementMin) return elementMin->luminosite(rayonMin,*this);
    else return 1.;
}

World::~World() { for (Elements::const_iterator i=elements.begin(); i!=elements.end(); i++) { delete *i; } }
