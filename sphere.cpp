#include "sphere.h"

#include <cstdlib>
#include <algorithm>

Sphere::Sphere(const Position &pos, float diam, Material mat) : position(pos), radius2((diam / 2)*(diam / 2)), mat(mat) { }

void Sphere::translate(const Direction &dx) {
    this->position += dx;
}

float Sphere::isIntersection(const LightRay & ray) {
    Vector3f sphereToRayOrigin = this->position - ray.origin;

    float projection = sphereToRayOrigin * ray.direction;

    // the dot product will be <0 if the sphere center is behind the ray
    if (projection < 0)
        return -1.0f;

    // compute minimal distance between ray and sphere center
    float d2 = sphereToRayOrigin * sphereToRayOrigin - projection * projection;

    // check if this distance it larger than the radius (distance squared and radius squared)
    if (d2 > this->radius2)
        return -1.0f;

    // We know that the ray intersect the sphere, now we try get the intersection location

    float intersectionOffset = sqrtf(this->radius2 - d2);
    this->lastRay.distance = std::min(projection - intersectionOffset, projection + intersectionOffset);
    this->lastRay.intersection = ray.origin + ray.direction * lastRay.distance;
    return this->lastRay.distance;
}

Light Sphere::luminosity(const LightRay &ray, const World &world) const {
    Position N = lastRay.intersection - this->position;
    N.makeUnitVector();

    float res = world.globalLight.direction * N;
    if (res > mat.specular)
        return Light(Color(1.f, 1.f, 1.f), 1.f);
    else if (res < 0)
        return world.background;
    else
        return world.background + Light(world.globalLight.c * mat.color * mat.diffuse, res);
}

/*
#include "vecteur3.h"
#include <cmath>

int profondeur;

class Sphere: public Element {
    private:
        Vecteur3f position;
        Vecteur3f positionLastIntersection;
        Vecteur3f lightRay;
        Vecteur3f vecteurIncident;
        float diametre;
        float distance;
        float r2; // ray * ray
            
    public:
        Sphere(Vecteur3f pos, float diam):position(pos), diametre(diam) {
            this->r2 = (this->diametre / 2) * (this->diametre / 2);
            this->lightRay = Vecteur3f(-5,5,-5);
            this->lightRay.normer();
        }

        bool isIntersection(Vecteur3f origineRayon, Vecteur3f directionRayon) {
            Vecteur3f L;
            float t_ca, t_hc; 
            float d2;
            
            L = this->position - origineRayon;
            t_ca = L * directionRayon;
            if(t_ca < 0) return false;
            d2 = L * L - t_ca * t_ca;
            if(d2 > this->r2) return false;
            t_hc = std::sqrt(this->r2 - d2);
            this->distance = my_min(t_ca - t_hc, t_ca + t_hc);
            this->positionLastIntersection = origineRayon + directionRayon * this->distance;
            this->vecteurIncident = directionRayon;
            return this->distance > 0;

            // directionRayon doit être normé.. A=1 dans ce cas donc il est ignoré....
            T B = 2*(directionRayon * (origineRayon - this->position));
            T C = (origineRayon - this->position ).norme() - (this->ray * this->ray);
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
            
        }
    
        float distanceIntersection() {
            return this->distance;
        }



        float luminosite(std::vector<Element * > monde) {
            Vecteur3f N = (this->positionLastIntersection - this->position);
            N.normer();
            float res = this->lightRay * N;
            if(profondeur < 3) {
            std::vector<Element* >::const_iterator it;
            for( it = monde.begin(); it != monde.end(); ++it) {
               if((*it) != this && (*it)->isIntersection(this->positionLastIntersection, N - this->vecteurIncident) ) {
                   if( (*it)->distanceIntersection() > 0)
                       profondeur ++;
                       res = (res + (*it)->luminosite(monde)) / 2;
                       profondeur --;
               }
            }
            }
            return my_max(res, 0);
        }
                  
};


 */