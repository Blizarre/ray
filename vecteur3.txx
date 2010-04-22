template <class T> Vecteur3<T>::Vecteur3(T x, T y, T z) {
    this->val[0] = x;
    this->val[1] = y;
    this->val[2] = z;
}

template <class T> Vecteur3<T>::Vecteur3() {
}

template <class T> Vecteur3<T>::Vecteur3(T* v) {
    this->val[0] = v[0];
    this->val[1] = v[1];
    this->val[2] = v[2];
}

template <class T> T&  Vecteur3<T>::operator[] (unsigned int i) {
    return this->val[i];
}

template <class T> T Vecteur3<T>::X() {
    return this->val[0];
}

template <class T> T Vecteur3<T>::Y() {
    return this->val[1];
}

template <class T> T Vecteur3<T>::Z() {
    return this->val[2];
}

template <class T> T Vecteur3<T>::norme() {
    return sqrt(this->val[0] * this->val[0] + this->val[1] * this->val[1] + this->val[2] * this->val[2]);
}

template <class T> void Vecteur3<T>::normer() {
    T norme = this->norme();

    this->val[0] /= norme;
    this->val[1] /= norme;
    this->val[2] /= norme;
}

template <class T> void Vecteur3<T>::normer(T val) {
    T norme = this->norme();
    T facteur = norme / val;
  
    this->val[0] *= facteur;
    this->val[1] *= facteur;
    this->val[2] *= facteur;
}

template <class T> T Vecteur3<T>::operator*(Vecteur3<T> op) {
    return this->val[0] * op.val[0] + this->val[1] * op.val[1] + this->val[2] * op.val[2];
}

template <class T> Vecteur3<T> Vecteur3<T>::operator*(T op) {
    return Vecteur3<T>(this->val[0] * op, this->val[1] * op, this->val[2] * op);
}

template <class T> Vecteur3<T> Vecteur3<T>::operator+(Vecteur3<T> op) {
    return Vecteur3<T>(this->val[0] + op.val[0], this->val[1] + op.val[1], this->val[2] + op.val[2]);
}

template <class T> Vecteur3<T> Vecteur3<T>::operator-(Vecteur3<T> op) {
    return Vecteur3<T>(this->val[0] - op.val[0], this->val[1] - op.val[1], this->val[2] - op.val[2]);
}
