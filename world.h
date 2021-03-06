#pragma once

#include "element.h"
#include "lightray.h"
#include "lightSource.h"

#include <list>
#include <limits>

// to resolve circular dependency ELement <-> World 
class Element;

typedef std::list<Element*> Elements;

class World {
public:

    World(LightSource globalLight, Light background) : globalLight(globalLight), background(background) {
    }

    World() {
        globalLight.c = {1.f, 1.f, 1.f};
        globalLight.direction = {0.5f, -0.5f, -0.5f};
        background = 0.5f;
    }

    Light rayTracing(LightRay &ray, const Element *from) const;
    ~World();
    LightSource globalLight;
    Elements elements;
    Light background;
};
