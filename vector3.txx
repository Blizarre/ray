#pragma once

template <class T> Vector3<T>::Vector3(T x, T y, T z) {
    this->val[0] = x;
    this->val[1] = y;
    this->val[2] = z;
}

template <class T> Vector3<T>::Vector3() {
}

template <class T> Vector3<T>::Vector3(T* v) {
    this->val[0] = v[0];
    this->val[1] = v[1];
    this->val[2] = v[2];
}

template <class T> T& Vector3<T>::operator[](unsigned int i) {
    return this->val[i];
}

template <class T> T Vector3<T>::X() const {
    return this->val[0];
}

template <class T> T Vector3<T>::Y() const {
    return this->val[1];
}

template <class T> T Vector3<T>::Z() const {
    return this->val[2];
}

template <class T> T Vector3<T>::getNorm() const {
    return sqrt(this->val[0] * this->val[0] + this->val[1] * this->val[1] + this->val[2] * this->val[2]);
}

template <class T> void Vector3<T>::makeUnitVector() {
    T norme = this->getNorm();

    this->val[0] /= norme;
    this->val[1] /= norme;
    this->val[2] /= norme;
}

template <class T> T Vector3<T>::operator*(const Vector3<T> &op) const {
    return this->val[0] * op.val[0] + this->val[1] * op.val[1] + this->val[2] * op.val[2];
}

template <class T> Vector3<T> Vector3<T>::operator*(T op) const {
    return Vector3<T>(this->val[0] * op, this->val[1] * op, this->val[2] * op);
}

template <class T> Vector3<T> Vector3<T>::operator+(const Vector3<T> &op) const {
    return Vector3<T>(this->val[0] + op.val[0], this->val[1] + op.val[1], this->val[2] + op.val[2]);
}

template <class T>
Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &v) {
    for (int i = 0; i < 3; i++) {
        this->val[i] += v.val[i];
    }
    return *this;
}

template <class T> Vector3<T> Vector3<T>::operator-(const Vector3<T> &op) const {
    return Vector3<T>(this->val[0] - op.val[0], this->val[1] - op.val[1], this->val[2] - op.val[2]);
}

template <class T> std::ostream &operator<<(std::ostream &s, const Vector3<T> &t) {
    return s << t.X() << " " << t.Y() << " " << t.Z();
}
