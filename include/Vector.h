#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <math.h>

template <class T>
class Vector {
    public:
        Vector();
        Vector(const T& new_x, const T& new_y);
        Vector(Vector<T> const& new_vector);

        T getX() const;
        T getY() const;

        void setValue(const T& new_x, const T& new_y);

        Vector<T> operator+ () const; //unary
        Vector<T> operator- () const; //unary

        Vector<T> operator+= (const Vector<T>& another);
        Vector<T> operator-= (const Vector<T>& another);
        Vector<T> operator*= (const T& a);

        T getLength () const;
        T getScalarMult (const Vector<T>& another) const;

        bool operator== (const Vector<T>& another) const;
        bool operator!= (const Vector<T>& another) const;

//        void printCoordinates ();

    protected:
        T x;
        T y;
};

template <class T>
Vector<T> operator+ (const Vector<T>& a, const Vector<T>& b);

template <class T>
Vector<T> operator- (const Vector<T>& a, const Vector<T>& b);

template <class T>
Vector<T> operator* (const T& a, const Vector<T>& v);

template <class T>
Vector<T> operator* (const Vector<T>& v, const T& a);

template <class T>
Vector<T>::Vector() {
    setValue (0, 0);
}

template <class T>
Vector<T>::Vector(const T& new_x, const T& new_y): x(new_x), y(new_y) {}

template <class T>
Vector<T>::Vector(const Vector<T>& new_vector): x(new_vector.x), y(new_vector.y) {}

template <class T>
T Vector<T>::getX() const {
    return x;
}

template <class T>
T Vector<T>::getY() const {
    return y;
}

template <class T>
void Vector<T>::setValue(const T& new_x, const T& new_y) {
    x = new_x;
    y = new_y;
}

template <class T>
Vector<T> Vector<T>::operator+ () const { //unary
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator- () const { //unary
    return -1*(*this);
}


template <class T>
Vector<T> Vector<T>::operator+= (const Vector<T>& another) {
    setValue(x+another.x, y+another.y);
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator-= (const Vector<T>& another) {
    setValue(x-another.x, y-another.y);
    return *this;
}


template <class T>
Vector<T> Vector<T>::operator*= (const T& a){
    setValue(x*a, y*a);
    return *this;
}

template <class T>
Vector<T> operator+ (const Vector<T>& a, const Vector<T>& b){ //binary
    Vector<T> tmp = a;
    return tmp+=b;
}

template <class T>
Vector<T> operator- (const Vector<T>& a, const Vector<T>& b){ //binary
    Vector<T> tmp = a;
    return tmp-=b;
}

template <class T>
Vector<T> operator* (const T& a, const Vector<T>& v){
    Vector<T> tmp = v;
    return tmp*=a;
}

template <class T>
Vector<T> operator* (const Vector<T>& v, const T& a){
    return a*v;
}

template <class T>
T Vector<T>::getLength () const {
    return sqrt(x*x + y*y);
}


template <class T>
T Vector<T>::getScalarMult (const Vector<T>& another) const {
    return (x*another.x + y*another.y);
}


template <class T>
bool Vector<T>::operator== (const Vector<T>& another) const {
    return (another.x == x && another.y == y);
}

template <class T>
bool Vector<T>::operator!= (const Vector<T>& another) const {
    return !(*this == another);
}

template <class T>
std::ostream& operator << (std::ostream& os, const Vector<T>& output) {
    os << "(" << output.getX() << ", " << output.getY() << ")" ;
    return os;
}

#endif // VECTOR_H
