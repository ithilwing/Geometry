#ifndef  CIRCLE_H
#define  CIRCLE_H

template <class T>
class  Circle
{
    public:
        Circle();
        Circle(const Vector<T>& p, const Vector<T>& r);
        Circle(const Vector<T>& p, const T& r);

    protected:
        Vector<T> point;
        T radius;
};

template <class T>
Circle<T>::Circle(const Vector<T>& p, const Vector<T>& r): point(p), radius(r.getLength()) {}

template <class T>
Circle<T>::Circle(const Vector<T>& p, const T& r): point(p), radius(r){}

#endif //  CIRCLE_H
