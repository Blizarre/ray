#include<cmath>
#include<ostream>

#ifndef __MY_VECTOR__0ff0 
#define __MY_VECTOR__0ff0


template<class T>
class Vecteur3 {
public:
    Vecteur3(T x, T y, T z);
    Vecteur3(T* v);
    Vecteur3();
    T X() const;
    T Y() const;
    T Z() const;
    T norme() const;
    void normer();
    void normer(T);
    T& operator[](unsigned int);

    T operator*(const Vecteur3<T> &) const;
    Vecteur3<T> operator*(T op) const;
    Vecteur3<T> operator+(const Vecteur3<T> &) const;
    Vecteur3<T> &operator+=(const Vecteur3<T> &);
    Vecteur3<T> operator-(const Vecteur3<T> &) const;

private:
    T val[3];
};

template <class T>
std::ostream& operator<<(std::ostream& s, const Vecteur3<T> &t);

#include "vecteur3.txx"

typedef Vecteur3<float> Direction;
typedef Vecteur3<float> Position;

#endif
