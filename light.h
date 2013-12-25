#include "Color.h"

#ifndef _LIGHT_OX343

#define _LIGHT_OX343

class Light {
public:
	Light(Color c, float f) : light(f), col(c) { }
	Light(Color c) : light(1.f), col(c) { }
	Light(float f) : light(f), col(Color(1.f, 1.f, 1.f)) { }
	Light() : light(0.f) { }

	Light operator+(const Light &l) const {
		return Light(l.col * this->col, l.light + this->light);
	}

	Light operator*(const float &f) const {
		return Light(f * this->light);
	}

	float light;
	Color col;
};

#endif