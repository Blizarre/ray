#pragma once

#include "light.h"

class Material {
public:

    Material() : specular(0.f), diffuse(0.f), color(Color(1.f, 0.f, 0.f)), reflectiveIndex(0.f) {
    }

    Material(float specular, float diffuse, Color color, float reflectiveIndex, float transparency) :
    specular(specular), diffuse(diffuse), color(color), reflectiveIndex(reflectiveIndex), transparency(transparency) {
    }

    float specular;
    float diffuse;
    Color color;
    float reflectiveIndex;
    float transparency;

    static Material glass() {
        return Material(0.9f, 0.1f, Color(1.f, 1.f, 1.f), 1.5f, 0.3f);
    };

    static Material redGlass() {
        return Material(0.9f, 0.3f, Color(1.f, 0.f, 0.f), 1.5f, 0.3f);
    };

    static Material RedPlastic() {
        return Material(0.8f, 1.f, Color(1.f, 0.2f, 0.2f), 0.f, 0.f);
    };

    static Material silver() {
        return Material(0.8f, 1.f, Color(0.8f, 0.8f, 0.8f), 0.f, 0.f);
    };

    static Material concrete() {
        return Material(1.f, 0.5f, Color(0.3f, 0.3f, 0.3f), 0.f, 0.f);
    };
};
