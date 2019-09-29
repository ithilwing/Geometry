#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <math.h>

#include "Vector.h"

template <class T>
class Segment
{
    public:
        Segment();
        Segment (const Vector<T>& new_one, const Vector<T>& new_two);
        Segment (const double& newx1, const double& newx2, const double& newy1, const double& newy2);

        void printCoordinates ();

        double getLength ();

    protected:
        Vector<T> one;
        Vector<T> two;
    private:
};

template <class T>
Segment<T>::Segment(const Vector<T>& new_one, const Vector<T>& new_two) {
    one = new_one;
    two = new_two;
}

template <class T>
Segment<T>::Segment(const double& newx1, const double& newx2, const double& newy1, const double& newy2) {
    one.setValue(newx1, newy1);
    two.setValue(newx2, newy2);
}

template <class T>
void Segment<T>::printCoordinates () {
    std::cout << "(" << one.getX() << ", " << one.getY() << "), (" << two.getX() << ", " << two.getY() << ")" << std::endl;
}

template <class T>
double Segment<T>::getLength () {
    Vector<T> tmp;
    tmp = two - one;
    return tmp.getLength();
}

#endif // SEGMENT_H
