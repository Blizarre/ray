#include<cmath>
#include<ostream>

#ifndef __MY_VECTOR__0ff0 

#define __MY_VECTOR__0ff0

template<class T> class Vecteur3 {

private:
    T val[3];

public:
    Vecteur3(T x, T y, T z);
    Vecteur3(T* v);
    Vecteur3();
    T X();
    T Y();
    T Z();
    T norme();
    void normer();
    void normer(T);
    T& operator[](unsigned int);
    T operator*(Vecteur3<T>);
    Vecteur3<T> operator*(T op);

    Vecteur3<T> operator+(Vecteur3<T>);
    Vecteur3<T> operator-(Vecteur3<T>);
    friend std::ostream& operator<<(std::ostream& s, Vecteur3& t)
    {
        return s << t.X() << " " << t.Y() <<" " << t.Z();
    }

};

#include"vecteur3.txx"

#endif
