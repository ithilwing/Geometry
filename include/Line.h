// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef LINE_H
#define LINE_H


#include "Shape.h"

template <class T>
class Line : public Shape<T>
{
    public:
        Line() {}

    protected:
        Vector<T> point;
        Vector<T> direction;
};

#endif // LINE_H
