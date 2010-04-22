#include"vecteur3.h"
#include <vector>

#ifndef __ELEMENT_0ff0
#define __ELEMENT_0ff0

typedef Vecteur3<float> Vecteur3f;

class Element {
    public:
        // Verifie si il y a une intersection avec l'element
        virtual bool isIntersection(Vecteur3f origine, Vecteur3f direction) { return false; };
        // Si une intersection a été détectée, il est possible d'en demander la distance. Sinon, exception
        virtual float distanceIntersection()  { return 0; };
        // Si l'élément émet de la lumière. 0 si pas de lumière
        
        virtual void deplacer(Vecteur3f d) { };

        virtual float luminosite(std::vector<Element* >) { return 0;};
};

#endif
