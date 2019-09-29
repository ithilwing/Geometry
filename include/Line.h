#ifndef LINE_H
#define LINE_H

template <class T>
class Line
{
    public:
        Line() {}

    protected:
        Vector<T> point;
        Vector<T> direction;
};

#endif // LINE_H
