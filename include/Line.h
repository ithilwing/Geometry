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
