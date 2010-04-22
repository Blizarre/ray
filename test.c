#include <cmath>
#include <vector>
#include<iostream>
#include <algorithm>
#include<map>

#include <limits>
#include"simpleSDL.h"
#include"Element.h"
#include"sphere.h"
#include"vecteur3.h"

#define SCREEN_INIT_ERROR (5)
#define RETURN_OK (0)

using namespace std;


typedef float flottant;
typedef Vecteur3<flottant> Vecteur3f;
typedef Element<flottant> Elementf;
typedef std::vector< Elementf* > VectorE;


flottant tanx, tany;

Vecteur3f definirDirection(int x, int y) {
    Vecteur3f direction;
    direction[0] = tanx * ( (flottant)2*x - LARGEUR ) / (LARGEUR);
    direction[1] = tany * ( (flottant)2*y - HAUTEUR ) / (HAUTEUR);
    direction[2] = 1;
    return direction;
}


Uint8 rayTracing(Vecteur3f origine, Vecteur3f direction,VectorE &monde) {
    Elementf* resultat = NULL;
    flottant distanceMin = numeric_limits<flottant>::max();
    flottant tmp;
    VectorE::iterator it;

    for( it=monde.begin(); it != monde.end(); ++it) {
        if ((*it)->isIntersection(origine, direction)) {
            if( (tmp=(*it)->distanceIntersection()) < distanceMin) {
                resultat = (*it);
                distanceMin = tmp;
            }
        }
    }
    if(resultat)
        return resultat->luminosite(monde);
    else
        return 255;
}

int main() {
    SDL_Surface *screen; //This pointer will reference the backbuffer 
    screen = InitVideo();
    SDL_ShowCursor(SDL_DISABLE);
    SDL_WM_GrabInput(SDL_GRAB_ON);
    
    if(screen == NULL)
        exit(SCREEN_INIT_ERROR);

    Uint32 t1;
    int x, y;
    
    Vecteur3f camera(1,1,1);
    Vecteur3f direction;
    VectorE monde;
    monde.push_back( new Sphere<flottant>(Vecteur3f(2,0,25), 10));
    monde.push_back( new Sphere<flottant>(Vecteur3f(0,2,4), 0.5));
    monde.push_back( new Sphere<flottant>(Vecteur3f(-1,-1.5,5.5), 2));

    tanx = tan((flottant)M_PI/4.0);
    tany = tan( (HAUTEUR / (flottant)LARGEUR) * M_PI/4.0);
    
    SDL_Event event;
    while (1) { 
        
        while( SDL_PollEvent(&event) ) {
            if(event.type == SDL_MOUSEMOTION) {
                camera[0] += 0.01 * (event.motion.xrel);
                camera[1] += 0.01 * (event.motion.yrel);
            }
            if(event.type == SDL_KEYDOWN) {
                exit(RETURN_OK);
            }
            if(event.type == SDL_QUIT) {
                exit(RETURN_OK);
            }
        }
        t1=SDL_GetTicks();
        for(x=0;x<LARGEUR;x++)
            for(y=0;y<HAUTEUR;y++) {
                direction = definirDirection(x, y);
                direction.normer();
                definirPixel(screen, x, y, rayTracing(camera, direction, monde));
            }
        SDL_Flip(screen);
        printf("temps: %1d\n", SDL_GetTicks()-t1);
    }

   SDL_FreeSurface(screen);  
   VectorE::iterator it;
   for( it=monde.begin(); it != monde.end(); ++it) {
       delete (*it);
   }    

   return RETURN_OK;
}
