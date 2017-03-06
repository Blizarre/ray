#include "rayon.h"


Rayon::Rayon(const Position &origine, const Direction &direction) : origine(origine), direction(direction), intersection(0, 0, 0), distance(0) {}

Rayon::Rayon()  { }

void Rayon::update(const Rayon &rayon) {
	intersection = rayon.intersection;
	distance = rayon.distance;
}
