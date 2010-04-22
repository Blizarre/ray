#include"vecteur3.h"
#include<vector>

#ifndef __ELEMENT_0ff0
#define __ELEMENT_0ff0

template<class T> class Element {
    public:
        // Verifie si il y a une intersection avec l'element
        virtual bool isIntersection(Vecteur3<T> origine, Vecteur3<T> direction) { return false; };
        // Si une intersection a été détectée, il est possible d'en demander la distance. Sinon, exception
        virtual T distanceIntersection() { return 0; };
        // Si l'élément émet de la lumière. 0 si pas de lumière
        virtual T luminosite(std::vector<Element<T>* >) { return 0;};
};

#endif
