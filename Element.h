#ifndef __ELEMENT_0ff0
#define __ELEMENT_0ff0

#include"vecteur3.h"
#include <vector>

typedef Vecteur3<float> Vecteur3f;

class Element {
public:
    // Verifie si il y a une intersection avec l'element
    virtual bool isIntersection(Vecteur3f origine, Vecteur3f direction) =0;

    // Si une intersection a été détectée, il est possible d'en demander la distance. Sinon, exception
    virtual float luminosite(std::vector<Element* >) =0;
    virtual float distanceIntersection()  =0;
    
    virtual void deplacer(Vecteur3f d) =0;
};

#endif
