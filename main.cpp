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

static const float tanx = tanf(static_cast<float> (M_PI) / 4.0f);
static const float tany = tanf(static_cast<float> (SCREEN_HEIGH) / static_cast<float> (SCREEN_WIDTH) * static_cast<float> (M_PI) / 4.0f);

Direction definirDirection(Direction &direction, float x, float y) {
    direction[0] = tanx * (2.f * x - SCREEN_WIDTH) / (SCREEN_WIDTH);
    direction[1] = tany * (2.f * y - SCREEN_HEIGH) / (SCREEN_HEIGH);
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
                //camera_ray.origin[0] += 0.01f
                //	* (event.motion.xrel);
                //camera_ray.origin[1] += 0.01f * (event.motion.yrel);
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

        //#pragma omp parallel
        for (int x = 0; x < SCREEN_WIDTH; x++) for (int y = 0; y < SCREEN_HEIGH; y++) {
                definirDirection(camera_ray.direction, static_cast<float> (x), static_cast<float> (y));
                Light value = world.rayTracing(camera_ray, NULL);
                definirPixel(screen, x, y, lightToPixel(value));
            }

        showImage(screen);
        printf("time: %1ums\n", SDL_GetTicks() - t1);
    }

    freeRenderer(screen);
    return RETURN_OK;
}
