#include "Color.h"

class Light {
public:
	Light(float f) : light(f) { }
	Light() : light(0.f) { }

	float light;
	Color col;
};
