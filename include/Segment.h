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
        Segment (const T& newx1, const T& newx2, const T& newy1, const T& newy2);

        T getLength (); // what if sqrt cannot accept T ?

        template <class V>
        friend std::ostream &operator << (std::ostream &os, const Segment<V> &output);


    protected:
        Vector<T> one;
        Vector<T> two;
};

template <class T>
Segment<T>::Segment(const Vector<T>& new_one, const Vector<T>& new_two) {
    one = new_one;
    two = new_two;
}

template <class T>
Segment<T>::Segment(const T& newx1, const T& newx2, const T& newy1, const T& newy2) {
    one.setValue(newx1, newy1);
    two.setValue(newx2, newy2);
}


template <class T>
std::ostream& operator << (std::ostream& os, const Segment<T>& output) {
    os << output.one << ", " << output.two ;
    return os;
}

template <class T>
T Segment<T>::getLength () {
    Vector<T> tmp;
    tmp = two - one;
    return tmp.getLength();
}

#endif // SEGMENT_H
