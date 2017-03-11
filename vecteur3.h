#pragma once

#include<cmath>
#include<ostream>

template<class T>
class Vector3 {
public:
    Vector3(T x, T y, T z);
    Vector3(T* v);
    Vector3();
    T X() const;
    T Y() const;
    T Z() const;
    T getNorm() const;
    void makeUnitVector();
    void normer(T);
    T& operator[](unsigned int);

    T operator*(const Vector3<T> &) const;
    Vector3<T> operator*(T op) const;
    Vector3<T> operator+(const Vector3<T> &) const;
    Vector3<T> &operator+=(const Vector3<T> &);
    Vector3<T> operator-(const Vector3<T> &) const;

private:
    T val[3];
};

template <class T>
std::ostream& operator<<(std::ostream& s, const Vector3<T> &t);

#include "vector3.txx"

typedef Vector3<float> Direction;
typedef Vector3<float> Position;
