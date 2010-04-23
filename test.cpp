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



#define LARGEUR (512)
#define HAUTEUR (384)

using namespace std;


typedef float flottant;
typedef Vecteur3<flottant> Vecteur3f;
typedef std::vector< Element* > VectorE;


flottant tanx, tany;

Vecteur3f definirDirection(int x, int y) {
    Vecteur3f direction;
    direction[0] = tanx * ( (flottant)2*x - LARGEUR ) / (LARGEUR);
    direction[1] = tany * ( (flottant)2*y - HAUTEUR ) / (HAUTEUR);
    direction[2] = 1;
    return direction;
}


Uint8 rayTracing(const Vecteur3f &origine, const Vecteur3f &direction, const VectorE &monde) {
    Element* resultat = NULL;
    flottant distanceMin = numeric_limits<flottant>::max();
    flottant tmp;

    for(VectorE::const_iterator it=monde.begin(); it != monde.end(); ++it) {
        if ((*it)->isIntersection(origine, direction)) {
            if( (tmp=(*it)->distanceIntersection()) < distanceMin) {
                resultat = (*it);
                distanceMin = tmp;
            }
        }
    }
    if(resultat) {
        return 250*resultat->luminosite(monde);
    }
    else
        return 255;
}

int main() {
    SDL_Surface *screen; //This pointer will reference the backbuffer 
    screen = InitVideo(LARGEUR, HAUTEUR);
    
    if(screen == NULL)
        exit(SCREEN_INIT_ERROR);

    Uint32 t1;
    int x, y;
    
    Vecteur3f camera(1,1,1);
    Vecteur3f direction;
    VectorE monde;
    Sphere* mov = new Sphere(Vecteur3f(3,3,10), 5);
    monde.push_back( mov );
    monde.push_back( new Sphere(Vecteur3f(-3,3,10), 5));
    monde.push_back( new Sphere(Vecteur3f(-3,-3,10), 4));

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
        mov->deplacer( Vecteur3f(0,0,0.1 * (1 - 2* (((int)(t1/2000.0))%2)) ) );
        //#pragma omp parallel
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
