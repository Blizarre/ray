#include "world.h"

Light World::rayTracing(Rayon &rayon, const Element *from) const {

    const Element *elementMin = NULL;
    float distanceMin = std::numeric_limits<float>::max();
    float distance = 0;

    for (Elements::const_iterator it = elements.begin(); it != elements.end(); it++) {
        Element *elem = *it;
        if (elem != from && (distance = elem->isIntersection(rayon)) > 0 && distance < distanceMin) {
            elementMin = elem;
            distanceMin = distance;
        }
    }

    if (elementMin)
        return elementMin->luminosite(rayon, *this);
    else return background;
}

World::~World() {
    for (Elements::const_iterator i = elements.begin(); i != elements.end(); i++) {
        delete *i;
    }
}
