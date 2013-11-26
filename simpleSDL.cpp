#include<iostream>

#include"simpleSDL.h"

using namespace std;



SDL_Surface* InitVideo(int largeur, int hauteur) {
	Uint32 flags = 0; //SDL_DOUBLEBUF;
  SDL_Surface *screen;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cerr <<"Unable to initialize SDL: " <<SDL_GetError() <<endl;
    return NULL;
  }

  atexit(SDL_Quit); // Clean it up nicely :)
 
  screen = SDL_CreateWindow("RtRealTracing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largeur, hauteur, flags); //SDL_SetVideoMode(largeur, hauteur, 32, flags);
  if (screen == NULL) {
    cerr <<"Unable to set video mode: " <<SDL_GetError() <<endl;
  }

  SDL_ShowCursor(SDL_DISABLE);
  SDL_WM_GrabInput(SDL_GRAB_ON);

  return screen;
}


void definirPixel(SDL_Surface *surface, int x, int y, Uint8 pixel) {
    int nbOctetsParPixel = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * nbOctetsParPixel;
    p[0]=pixel;
    p[1]=pixel;
    p[2]=pixel;
}
