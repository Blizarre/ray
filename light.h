#include "Color.h"

class Light {
public:
	Light(float f) : light(f) { }
	Light() : light(0.f) { }

	Light operator+(const Light &l) const {
		return Light(l.light + this->light);
	}

	Light operator*(const float &f) const {
		return Light(f * this->light);
	}

	float light;
	Color col;
};
