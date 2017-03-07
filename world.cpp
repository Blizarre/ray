#include "world.h"

Light World::rayTracing(LightRay &ray, const Element *from) const {

    const Element *elementMin = NULL;
    float distanceMin = std::numeric_limits<float>::max();
    float distance = 0;

    for (Elements::const_iterator it = elements.begin(); it != elements.end(); it++) {
        Element *elem = *it;
        if (elem != from && (distance = elem->isIntersection(ray)) > 0 && distance < distanceMin) {
            elementMin = elem;
            distanceMin = distance;
        }
    }

    if (elementMin)
        return elementMin->luminosity(ray, *this);
    else return background;
}

World::~World() {
    for (Elements::const_iterator i = elements.begin(); i != elements.end(); i++) {
        delete *i;
    }
}
