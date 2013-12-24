#include "simpleSDL.h"
#include "element.h"
#include "sphere.h"
#include "plane.h"

static const int SCREEN_INIT_ERROR = 5;
static const int RETURN_OK = 0;

static const int LARGEUR = 512;
static const int HAUTEUR = 384;

static const float tanx = tanf(static_cast<float>(M_PI) / 4.0f);
static const float tany = tanf(static_cast<float>(HAUTEUR) / static_cast<float>(LARGEUR)* static_cast<float>(M_PI) / 4.0f);

Direction definirDirection(Direction &direction, float x, float y) {
	direction[0] = tanx * (2.f*x - LARGEUR) / (LARGEUR);
	direction[1] = tany * (2.f*y - HAUTEUR) / (HAUTEUR);
	direction[2] = 1.f;
	direction.normer();
	return direction;
}

Uint8 lightToPixelValue(Light l) {
	return static_cast<Uint8>(l.light * 255.0f);
}

// Need to be extern "C" for SDL
#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char *argv[]) {
	Uint32 *screen; //This pointer will reference the backbuffer 
	screen = InitVideo(LARGEUR, HAUTEUR);
	if (screen == NULL) exit(SCREEN_INIT_ERROR);

	Rayon camera_ray(Position(0,0,-3), Direction(0,0,1));
	World monde;

	Sphere* mov = new Sphere(Position(3, 3, 10), 5); monde.elements.push_back(mov);
	monde.elements.push_back(new Sphere(Position(-3, 3, 10), 5));
	monde.elements.push_back(new Sphere(Position(-3, -3, 10), 4));
	monde.elements.push_back(new Plane());

	while (1) {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEMOTION) {
				camera_ray.origine[0] += 0.01f * (event.motion.xrel);
				camera_ray.origine[1] += 0.01f * (event.motion.yrel);
			}
			if (event.type == SDL_KEYDOWN) {
				exit(RETURN_OK);
			}
			if (event.type == SDL_QUIT) {
				exit(RETURN_OK);
			}
		}

		Uint32 t1 = SDL_GetTicks();
		mov->deplacer(Direction(0.f, 0.f, 0.1f * (1 - 2 * (((int)(t1 / 2000.0f)) % 2))));

		//#pragma omp parallel
		for (int x = 0; x < LARGEUR; x++) for (int y = 0; y < HAUTEUR; y++) {
			definirDirection(camera_ray.direction, static_cast<float>(x), static_cast<float>(y));
			Light value = monde.rayTracing(camera_ray, NULL);
			definirPixel(screen, x, y, lightToPixelValue(value));
		}

		showImage(screen);
		printf("temps: %1dms\n", SDL_GetTicks() - t1);
	}

	freeRenderer(screen);
	return RETURN_OK;
}

