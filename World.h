#ifndef _WORLD_0X34

#define _WORLD_0X34

#include "element.h"
#include "rayon.h"
#include "LightSource.h"
#include "Rayon.h"

#include <list>

class Element;

typedef std::list<Element*> Elements;

class World {
public:
	World(LightSource globalLight, Light background): globalLight(globalLight), background(background) {}
	World() {
		globalLight.c = { 0.f, 1.0f, 0.f };
		globalLight.direction = { 0.5f, 0.5f, 0.5f };
		background = 0.1f;
	}

	Light rayTracing(Rayon &rayon, const Element *from) const;
	~World();
	LightSource globalLight;
	Elements elements;
	Light background;
};

#endif