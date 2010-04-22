#include<iostream>

#include"simpleSDL.h"

using namespace std;



SDL_Surface* InitVideo() {
  Uint32 flags = SDL_DOUBLEBUF;
  SDL_Surface *screen;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cerr <<"Unable to initialize SDL: " <<SDL_GetError() <<endl;
    return NULL;
  }

  atexit(SDL_Quit); // Clean it up nicely :)
 
  screen = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, flags);
  if (screen == NULL) {
    cerr <<"Unable to set video mode: " <<SDL_GetError() <<endl;
  }
  return screen;
}


void definirPixel(SDL_Surface *surface, int x, int y, Uint8 pixel) {
    int nbOctetsParPixel = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * nbOctetsParPixel;
    p[0]=pixel;
    p[1]=pixel;
    p[2]=pixel;
}
