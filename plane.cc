#include "plane.h"

#include <cstdio>
#include <iostream>

Plane::Plane() {}

bool Plane::isIntersection(Rayon &rayon) const {
    //std::cout << rayon.direction << std::endl;
    rayon.distance = 1000.;
    return true;
}

float Plane::luminosite(const Rayon &rayon,const World &world) const {
    if (rayon.direction.X()>0 && rayon.direction.Y()>0) return .33;
    if (rayon.direction.X()>0 && rayon.direction.Y()<=0) return .25;
    if (rayon.direction.X()<=0 && rayon.direction.Y()>0) return .5;
    return .66;
}


