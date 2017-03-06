#ifndef _COLOR_0X4354

#define _COLOR_0X4354

class Color {
public:
    float Red;
    float Green;
    float Blue;

    // "Multiply" colors, components by components.

    Color operator*(const Color & c) const {
        return Color(c.Red * Red, c.Green * Green, c.Blue * Blue);
    }

    // Multiply all components by the factor f. Used to Dim the color.

    Color operator*(const float & f) const {
        return Color(Red * f, Green * f, Blue * f);
    }

    Color() : Red(0), Green(0), Blue(0) {
    }

    Color(float R, float G, float B) : Red(R), Green(G), Blue(B) {
    }
};

#endif