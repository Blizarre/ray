#include<iostream>

#include"simpleSDL.h"

using namespace std;

// Internal state
int largeur, hauteur;

static SDL_Renderer* renderer;
static SDL_Window* window;
static SDL_Texture *texture;

void freeRenderer(Uint32 *myPixels) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(texture);
	free(myPixels);
}

void showImage(Uint32 *myPixels) {
	SDL_UpdateTexture(texture, NULL, myPixels, largeur * sizeof (Uint32));
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

Uint32* InitVideo(int l, int h) {
	Uint32 flags = 0; //SDL_DOUBLEBUF;
	largeur = l;
	hauteur = h;
	Uint32 *data = (Uint32*)malloc(largeur * hauteur * sizeof(Uint32));

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Unable to initialize SDL: " << SDL_GetError() << endl;
		return NULL;
	}

	atexit(SDL_Quit); // Clean it up nicely :)

	if (SDL_CreateWindowAndRenderer(largeur, hauteur, flags, &window, &renderer)) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), window);
		exit(0);
	}

	SDL_SetRelativeMouseMode(SDL_TRUE);

	texture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		largeur, hauteur);

	return data;
}

class Pixel {
public:
	Uint8 R;
	Uint8 G;
	Uint8 B;
	Uint8 A;
};

void definirPixel(Uint32 *surface, int x, int y, Uint8 pixel) {
	Uint32 *p1 = surface + y * largeur + x;
	Pixel* p = (Pixel*)(p1);
	p->R = pixel;
	p->G = pixel;
	p->B = pixel;
	p->A = 0xff;
}
