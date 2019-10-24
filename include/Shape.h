// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

template <class T>
class Shape
{
public:
    virtual std::string toString () const {
        return "Shape";
    }
};

template <class T>
std::ostream& operator << (std::ostream& os, const Shape<T>& output) {
    os <<  output.toString();
    return os;
}

template <class T>
class NullShape : public Shape<T>
{
public:
    std::string toString() const;
    bool operator== (const NullShape<T>& another) const;
};

template <class T>
std::string NullShape<T>::toString() const {
    return "Null shape";
}

template <class T>
bool NullShape<T>::operator== (const NullShape<T>& another) const {
    return true;
}


#endif // SHAPE_H
