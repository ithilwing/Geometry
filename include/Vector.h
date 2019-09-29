
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <math.h>

template <class T>
class Vector {
    public:
        Vector();
        Vector(const double& new_x, const double& new_y);
        Vector(const Vector<T>& new_vector);

        double getX() const;
        double getY() const;

        void setValue(const double& new_x, const double& new_y);

        Vector<T> operator+ (const Vector<T>& another) const;
        Vector<T> operator- (const Vector<T>& another) const;

        template <class V>
        friend Vector<V> operator* (const double& a, const Vector<V>& v);

        double getLength () const;
        double getScalarMult (const Vector<T>& another) const;

        bool operator== (const Vector<T>& another) const;
        bool operator!= (const Vector<T>& another) const;

        void printCoordinates ();

    protected:
        double x;
        double y;
};

template <class T>
Vector<T>::Vector() {
    setValue (0, 0);
}

template <class T>
Vector<T>::Vector(const double& new_x, const double& new_y) {
    setValue(new_x, new_y);
}

template <class T>
Vector<T>::Vector(const Vector<T>& new_vector) {
    setValue(new_vector.x, new_vector.y);
}

template <class T>
double Vector<T>::getX() const {
    return x;
}

template <class T>
double Vector<T>::getY() const {
    return y;
}

template <class T>
void Vector<T>::setValue(const double& new_x, const double& new_y) {
    x = new_x;
    y = new_y;
}

template <class T>
Vector<T> Vector<T>::operator+ (const Vector<T>& another) const {
    Vector<T> tmp;
    tmp.x = x + another.x;
    tmp.y = y + another.y;
    return tmp;
}

template <class T>
double Vector<T>::getLength () const {
    return sqrt(x*x + y*y);
}

template <class T>
Vector<T> operator* (const double& a, const Vector<T>& v) {
    Vector<T> tmp;
    tmp.x = v.x * a;
    tmp.y = v.y * a;
    return tmp;
}

template <class T>
double Vector<T>::getScalarMult (const Vector<T>& another) const {
    return (x*another.x + y*another.y);
}

template <class T>
Vector<T> Vector<T>::operator- (const Vector<T>& another) const {
    return (*this + (-1)*another);
}

template <class T>
bool Vector<T>::operator== (const Vector<T>& another) const {
    if (another.x == x && another.y == y) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
bool Vector<T>::operator!= (const Vector<T>& another) const {
    if (another.x == x && another.y == y) {
        return false;
    }
    else {
        return true;
    }
}

template <class T>
void Vector<T>::printCoordinates () {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

#endif // VECTOR_H
