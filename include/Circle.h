
#ifndef  CIRCLE_H
#define  CIRCLE_H

template <class T>
class  Circle
{
    public:
        Circle();
        Circle(const Vector<T>& p, const Vector<T>& r);

    protected:
        Vector<T> point;
        double radius;
    private:
};

template <class T>
Circle<T>::Circle(const Vector<T>& p, const Vector<T>& r) {
    point = p;
    radius = r.getLength();
}

#endif //  CIRCLE_
