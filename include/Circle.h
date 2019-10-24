// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef  CIRCLE_H
#define  CIRCLE_H

#include "Shape.h"

template <class T>
class  Circle : public Shape<T>
{
    public:
        Circle(); //default constructor from Shape
        Circle(const Vector<T>& p, const Vector<T>& r); // from two vectors
        Circle(const Vector<T>& p, const T& r); //from vector and radius value
        Circle(const T& px, const T& py, const T& r); // from centre coordinates and radius value

        Vector<T> getPoint () const;
        T getRadius () const;

        std::string toString() const;

    protected:
        Vector<T> point;
        T radius;
};

template <class T>
Shape<T>* GetIntersection (const Circle<T>& a, const Circle<T>& b);

template <class T>
Circle<T>::Circle(const Vector<T>& p, const Vector<T>& r): point(p), radius(r.getLength()) {}

template <class T>
Circle<T>::Circle(const Vector<T>& p, const T& r): point(p), radius(r){}

template <class T>
Circle<T>::Circle(const T& px, const T& py, const T& r): point(px,py), radius(r){}

template <class T>
T Circle<T>::getRadius () const{
    return radius;
}

template <class T>
Vector<T> Circle<T>::getPoint() const{
    return point;
}

template <class T>
std::string Circle<T>::toString () const {
    return  point.toString() + ", r = " + std::to_string(radius);
}


template <class T>
Shape<T>* GetIntersection (const Circle<T>& a, const Circle<T>& b){
    Vector<T> p1 = a.getPoint();
    Vector<T> p2 = b.getPoint();

    T r1 = a.getRadius();
    T r2 = b.getRadius();

//formulas from https://planetcalc.ru/8098/?license=1

    Segment<T> connect(p1,p2); // segment connecting centres
    T d = connect.getLength(); //its length
    if (d > (r1+r2))
        return new NullShape<T> ();
    else if (d<EPS && std::abs(r1-r2)<EPS)
        return new Circle<T> (p1, r1);
    else {
        T a = (r1*r1-r2*r2+d*d)/(2*d);
        T h = sqrt(r1*r1-a*a);
        Vector<T> p3 = p1 + (a/d)*(p2-p1);

        T ip1x = p3.getX()+(h/d)*(p2.getY()-p1.getY());
        T ip1y = p3.getY()-(h/d)*(p2.getX()-p1.getX());
        T ip2x = p3.getX()-(h/d)*(p2.getY()-p1.getY());
        T ip2y = p3.getY()+(h/d)*(p2.getX()-p1.getX());

        if (std::abs(ip1x-ip2x)<EPS && std::abs(ip1y-ip2y)<EPS)
            return new Vector<T> (ip1x, ip1y);
        else
            return new Segment<T> (ip1x, ip1y, ip2x, ip2y);
    }

}

#endif //  CIRCLE_H
