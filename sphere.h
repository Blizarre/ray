#include"Element.h"
#include"vecteur3.h"
#include<cmath>
#include<iostream>

#ifndef __SPHERE_0ff1
#define __SPHERE_0ff1

#define my_max(a,b) ((a)<(b)?(b):(a))
#define my_min(a,b) ((a)>(b)?(b):(a))
#define my_sign(a) ((a)<0?(-1):(+1))


template <class T> class Sphere: public Element<T> {
    private:
        Vecteur3<T> position;
        Vecteur3<T> positionLastIntersection;
        Vecteur3<T> lightRay;
        T diametre;
        T distance;
        T r2; // Rayon * Rayon
            
    public:
        Sphere(Vecteur3<T> pos, T diam):position(pos), diametre(diam) {
            this->r2 = (this->diametre / 2) * (this->diametre / 2);
            this->lightRay = Vecteur3<T>(-5,5,-3);
            this->lightRay.normer();
        }

        bool isIntersection(Vecteur3<T> origineRayon, Vecteur3<T> directionRayon) {
            Vecteur3<T> L;
            T t_ca, t_hc; 
            T d2;
            
            L = this->position - origineRayon;
            t_ca = L * directionRayon;
            if(t_ca < 0) return false;
            d2 = L * L - t_ca * t_ca;
            if(d2 > this->r2) return false;
            t_hc = std::sqrt(this->r2 - d2);
            this->distance = my_min(t_ca - t_hc, t_ca + t_hc);
            this->positionLastIntersection = origineRayon + directionRayon * this->distance;
            return this->distance > 0;

            // directionRayon doit être normé.. A=1 dans ce cas donc il est ignoré....
            /*T B = 2*(directionRayon * (origineRayon - this->position));
            T C = (origineRayon - this->position ).norme() - (this->rayon * this->rayon);
            T Q, x1, x2;

            T delta = (B * B - 4 * C);

            if ( delta >= (T)0 ) {
                x1 = (-B-std::sqrt(delta)/2);
                x2 = (-B+std::sqrt(delta)/2);
                this->distance = my_min(x1,x2);
                //Q = -0.5 * ( B + my_sign(B) * sqrt(delta) );
                //this->distance = my_min(Q, C/Q);
                return this->distance > 0;
            } else
                return false;
            */
        }
    
        T distanceIntersection() {
            return this->distance;
        }


        T luminosite(std::vector<Element<T> * > monde) {
            Vecteur3<T> N = (this->positionLastIntersection - this->position);
            N.normer();
            T res = this->lightRay * N;
            return my_max(res*255,0);
        }
                  
};


#endif
