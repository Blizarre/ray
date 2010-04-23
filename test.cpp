#include "simpleSDL.h"
#include "element.h"
#include "sphere.h"

static const int SCREEN_INIT_ERROR = 5;
static const int RETURN_OK = 0;

static const int LARGEUR = 512;
static const int HAUTEUR = 384;

static const float tanx = tanf(M_PI/4.0);
static const float tany = tanf( (HAUTEUR / LARGEUR) * M_PI/4.0);
    
Vecteur definirDirection(Vecteur &direction, float x, float y) {
    direction[0] = tanx * ( 2*x - LARGEUR ) / (LARGEUR);
    direction[1] = tany * ( 2*y - HAUTEUR ) / (HAUTEUR);
    direction[2] = 1;
    direction.normer();
    return direction;
}

int main() {
    SDL_Surface *screen; //This pointer will reference the backbuffer 
    screen = InitVideo(LARGEUR, HAUTEUR);
    if(screen == NULL) exit(SCREEN_INIT_ERROR);

    Vecteur camera_pos(1,1,1);
    Vecteur camera_dir(0,0,1);
    Rayon camera_ray(camera_pos,camera_dir);
    World monde;

    Sphere* mov = new Sphere(Vecteur(3,3,10), 5); monde.elements.push_back( mov );
    monde.elements.push_back( new Sphere(Vecteur(-3,3,10), 5));
    monde.elements.push_back( new Sphere(Vecteur(-3,-3,10), 4));

    while (1) { 
        
        SDL_Event event;
        while( SDL_PollEvent(&event) ) {
            if(event.type == SDL_MOUSEMOTION) {
                camera_pos[0] += 0.01 * (event.motion.xrel);
                camera_pos[1] += 0.01 * (event.motion.yrel);
            }
            if(event.type == SDL_KEYDOWN) {
                exit(RETURN_OK);
            }
            if(event.type == SDL_QUIT) {
                exit(RETURN_OK);
            }
        }

        Uint32 t1=SDL_GetTicks();
        mov->deplacer( Vecteur(0,0,0.1 * (1 - 2* (((int)(t1/2000.0))%2)) ) );

        //#pragma omp parallel
        for(int x=0;x<LARGEUR;x++) for(int y=0;y<HAUTEUR;y++) {
            definirDirection(camera_dir, x, y);
            float value = monde.rayTracing(camera_ray,NULL);
            definirPixel(screen, x, y, 255*value);
        }

        SDL_Flip(screen);
        printf("temps: %1dms\n", SDL_GetTicks()-t1);
    }

   SDL_FreeSurface(screen);  
   return RETURN_OK;
}
