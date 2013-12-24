#ifndef _RAYON_0X34

#define _RAYON_0X34

#include "vecteur3.h"


class Rayon {
public:
	Rayon(const Position& origine, const Direction &direction);
	Rayon();
	void update(const Rayon &rayon);

	Position origine;
	Direction direction;
	Position intersection;
	float distance;
	int depth;
};

#endif