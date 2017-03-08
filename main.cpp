#include "simpleSDL.h"
#include "element.h"
#include "sphere.h"
#include "plane.h"
#include "material.h"
#include <algorithm>

static const int SCREEN_INIT_ERROR = 5;
static const int RETURN_OK = 0;

static const int SCREEN_WIDTH = 512;
static const int SCREEN_HEIGH = 384;

// viewAngle is 90 deg. or PI/2
static const float halfViewAngleX = static_cast<float> (M_PI/ 2.0f);

static const float halfViewAngleY =
    halfViewAngleX * \
    (static_cast<float> (SCREEN_HEIGH) / static_cast<float> (SCREEN_WIDTH));

//         |angle a/
//         |     /
//         | 1  /
// - - - - |---*
//1/tan a  |  /
//         | /  viewAngle / 2 (or halfViewAngle)
// camera :-------
//           \
//            \
//             \
// a = M_PI/2 - viewAngle/2
// tan a = 1 / x
Direction screenPixelDirection(Direction &direction, float x, float y) {
    float alphaX = M_PI / 2.0f - halfViewAngleX * (x - SCREEN_WIDTH / 2.0f) / SCREEN_WIDTH;
    float alphaY = M_PI / 2.0f - halfViewAngleY * (y - SCREEN_HEIGH / 2.0f) / SCREEN_HEIGH;

    direction[0] = 1.0f / tanf(alphaX);
    direction[1] = 1.0f / tanf(alphaY);
    direction[2] = 1.f;
    direction.makeUnitVector();
    return direction;
}

Pixel lightToPixel(Light l) {
    Pixel p;
    p.R = static_cast<Uint8> (std::min(255.f, l.light * l.col.Red * 255.0f));
    p.G = static_cast<Uint8> (std::min(255.f, l.light * l.col.Green * 255.0f));
    p.B = static_cast<Uint8> (std::min(255.f, l.light * l.col.Blue * 255.0f));
    return p;
}

int main(int argc, char *argv[]) {
    Uint32 *screen; //This pointer will reference the backbuffer 
    screen = InitVideo(SCREEN_WIDTH, SCREEN_HEIGH);
    if (screen == NULL) exit(SCREEN_INIT_ERROR);

    LightRay camera_ray(Position(0, 0, -3), Direction(0, 0, 1));
    World world;

    Sphere* mov = new Sphere(Position(3, 3, 10), 5, Material::glass());
    world.elements.push_back(mov);
    world.elements.push_back(new Sphere(Position(-3, 3, 10), 5, Material::RedPlastic()));
    world.elements.push_back(new Sphere(Position(-3, -3, 10), 4, Material::silver()));
    world.elements.push_back(new Plane());

    while (1) {

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_MOUSEMOTION) {
                world.globalLight.direction[0] += 0.01f * (event.motion.xrel);
                world.globalLight.direction[1] += 0.01f * (event.motion.yrel);
            }
            if (event.type == SDL_KEYDOWN) {
                exit(RETURN_OK);
            }
            if (event.type == SDL_QUIT) {
                exit(RETURN_OK);
            }
        }

        Uint32 t1 = SDL_GetTicks();
        mov->translate(Direction(0.f, 0.f, 0.1f * (1 - 2 * (((int) (t1 / 2000.0f)) % 2))));

        for (int x = 0; x < SCREEN_WIDTH; x++) for (int y = 0; y < SCREEN_HEIGH; y++) {
                screenPixelDirection(camera_ray.direction, static_cast<float> (x), static_cast<float> (y));
                Light value = world.rayTracing(camera_ray, NULL);
                definirPixel(screen, x, y, lightToPixel(value));
            }

        showImage(screen);
        printf("time: %1ums\n", SDL_GetTicks() - t1);
    }

    freeRenderer(screen);
    return RETURN_OK;
}

