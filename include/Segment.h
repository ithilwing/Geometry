// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

#include "Vector.h"
#include "Shape.h"

template <class T>
class Segment : public Shape<T>
{
    public:
        Segment(); //everything is zero: default constructor from Shape
        Segment (const Vector<T>& new_one, const Vector<T>& new_two); //from 2 vectors
        Segment (const T& newx1, const T& newy1, const T& newy2, const T& newx2); // from 4 coordinates

        T getOneX () const;
        T getOneY () const;
        T getTwoX () const;
        T getTwoY () const;

        T getLength () const; // what if sqrt cannot accept T ?

        bool operator== (const Segment<T>& another) const;

        std::string toString() const;

       /* template <class V>
        friend std::ostream &operator << (std::ostream &os, const Segment<V> &output);*/


    protected:
        Vector<T> one;
        Vector<T> two;
};

template <class T>
Shape<T>* GetIntersection (const Segment<T>& a, const Segment<T>& b);

template <class T>
Segment<T>::Segment() {
    one.setValue(0, 0);
    two.setValue(0, 0);
}

template <class T>
Segment<T>::Segment(const Vector<T>& new_one, const Vector<T>& new_two) {
    one = new_one;
    two = new_two;
}

template <class T>
Segment<T>::Segment(const T& newx1, const T& newy1, const T& newx2, const T& newy2) {
    one.setValue(newx1, newy1);
    two.setValue(newx2, newy2);
}

template <class T>
T Segment<T>::getOneX() const {
    return one.getX();
}

template <class T>
T Segment<T>::getTwoX() const {
    return two.getX();
}

template <class T>
T Segment<T>::getOneY() const {
    return one.getY();
}

template <class T>
T Segment<T>::getTwoY() const {
    return two.getY();
}

template <class T>
std::string Segment<T>::toString () const {
    return  one.toString() + ", " + two.toString();
}

/*template <class T>
std::ostream& operator << (std::ostream& os, const Segment<T>& output) {
    os << output.one << ", " << output.two ;
    return os;
}*/

template <class T>
T Segment<T>::getLength () const {
    Vector<T> tmp;
    tmp = two - one;
    return tmp.getLength();
}

template <class T>
bool Segment<T>::operator== (const Segment<T>& another) const {
    return (std::abs(another.one.getX() - one.getX())<EPS && std::abs(another.one.getY() - one.getY())<EPS &&
            std::abs(another.two.getX() - two.getX())<EPS && std::abs(another.two.getY() - two.getY())<EPS);
}

template <class T>
bool le (const T& a, const T& b) { //a<=b
    return (a<b || std::abs(a-b)<EPS);
}

template <class T>
bool ge (const T& a, const T& b) { // a>=b
    return (a>b || std::abs(a-b)<EPS);
}

template <class T>
bool eq (const T& a, const T& b) { // a==b
    return (std::abs(a-b)<EPS);
}

template <class T>
Shape<T>* GetIntersection (const Segment<T>& a, const Segment<T>& b){

    //initialize coordinates
    T x1a = a.getOneX();
    T x2a = a.getTwoX();
    T y1a = a.getOneY();
    T y2a = a.getTwoY();

    T x1b = b.getOneX();
    T x2b = b.getTwoX();
    T y1b = b.getOneY();
    T y2b = b.getTwoY();

    //set X-s in ascending order
    if (ge(x1a,x2a)) {
        T tmpx = x1a;
        x1a = x2a;
        x2a = tmpx;

        T tmpy = y1a;
        y1a = y2a;
        y2a = tmpy;
    }

    if (ge(x1b,x2b)) {
        T tmpx = x1b;
        x1b = x2b;
        x2b = tmpx;

        T tmpy = y1b;
        y1b = y2b;
        y2b = tmpy;
    }

    //check if both segments are vertical
    if (eq(x2a,x1a) && eq(x2b,x1b)) {
        if (!eq(x1a,x1b)) {
            //std::cout << a << " and " << b << ": " << "No intersection" << std::endl;
            return new NullShape<T> ();
        } else {
            return CaseParallel(a,b);
        }
    }

    //check if 1st segment is vertical
    if (eq(x1a,x2a) && !eq(x1b,x2b)) {
        T Ab = (y2b-y1b)/(x2b-x1b);
        T Bb = y1b - Ab*x1b;
        T y = Ab*x1a + Bb;
        T x = x1a;
        if (le(std::min(x1a,x2a),x) && le(x,std::max(x1a,x2a)) && le(std::min(y1a,y2a),y) && le(y,std::max(y1a,y2a))
            && le(std::min(x1b,x2b),x) && le(x,std::max(x1b,x2b)) && le(std::min(y1b,y2b),y) && le(y,std::max(y1b,y2b))) {
            //std::cout << a << " and " << b << ": " << "Intersection point: (" << x << ", " << y << ")" << std::endl;
            return new Vector<T> (x,y);
        } else {
            //std::cout << a << " and " << b << ": " << "No intersection" << std::endl;
            return new NullShape<T> ();
        }

    }

    //check if 2nd segment is vertical
    if (!eq(x1a,x2a) && eq(x1b,x2b)) {
        T Aa = (y2a-y1a)/(x2a-x1a);
        T Ba = y1a - Aa*x1a;
        T y = Aa*x1b + Ba;
        T x = x1b;
        if (le(std::min(x1a,x2a),x) && le(x,std::max(x1a,x2a)) && le(std::min(y1a,y2a),y) && le(y,std::max(y1a,y2a))
             && le(std::min(x1b,x2b),x) && le(x,std::max(x1b,x2b)) && le(std::min(y1b,y2b),y) && le(y,std::max(y1b,y2b))) {
            //std::cout << a << " and " << b << ": " << "Intersection point: (" << x << ", " << y << ")" << std::endl;
            return new Vector<T> (x,y);
        } else {
            //std::cout << a << " and " << b << ": " << "No intersection" << std::endl;
            return new NullShape<T> ();
        }

    }

    //slopes
    T Aa = (y2a-y1a)/(x2a-x1a);
    T Ab = (y2b-y1b)/(x2b-x1b);

    //intercepts
    T Ba = y1a - Aa*x1a;
    T Bb = y1b - Ab*x1b;

    //check if segments are parallel
    if (eq(Aa,Ab)) {
        if (!eq(Ba,Bb)) {
            //std::cout << a << " and " << b << ": " << "No intersection" << std::endl;
            return new NullShape<T> ();
        } else {
            return CaseParallel(a,b);
        }
    }

    //intersection point
    T x = (Bb - Ba)/(Aa - Ab);
    T y = Aa*x + Ba;

    if (le(std::min(x1a,x2a),x) && le(x,std::max(x1a,x2a)) && le(std::min(y1a,y2a),y) && le(y,std::max(y1a,y2a)) &&
         le(std::min(x1b,x2b),x) && le(x,std::max(x1b,x2b)) && le(std::min(y1b,y2b),y) && le(y,std::max(y1b,y2b))) {
        //std::cout << a << " and " << b << ": " << "Intersection point: (" << x << ", " << y << ")" << std::endl;
        return new Vector<T> (x,y);
    } else {
        //std::cout << a << " and " << b << ": " << "No intersection" << std::endl;
        return new NullShape<T> ();
    }

}

template <class T>
Shape<T>* CaseParallel (const Segment<T>& a, const Segment<T>& b) {
    T x1a = a.getOneX();
    T x2a = a.getTwoX();
    T y1a = a.getOneY();
    T y2a = a.getTwoY();

    T x1b = b.getOneX();
    T x2b = b.getTwoX();
    T y1b = b.getOneY();
    T y2b = b.getTwoY();

    if (std::max(y1a, y2a) < std::min(y1b, y2b) || std::max(y1b, y2b) < std::min(y1a, y2a)) {
        //std::cout << a << " and " << b << ": " << "No intersection" << std::endl;
        return new NullShape<T> ();
    } else if (eq(std::max(y1a, y2a),std::min(y1b, y2b))) {
        //std::cout << a << " and " << b << ": " << "Intersection point: (" << x1a << ", " << std::max(y1a, y2a) << ")" << std::endl;
        return new Vector<T> (x1a,std::max(y1a, y2a));
    } else if (eq(std::max(y1b, y2b),std::min(y1a, y2a))) {
        //std::cout << a << " and " << b << ": " << "Intersection point: (" << x1a << ", " << std::max(y1b, y2b) << ")" << std::endl;
        return new Vector<T> (x1a,std::max(y1b, y2b));
    }
    if (ge(a.getLength(),b.getLength())) {
        if (std::min(y1b, y2b) < std::max(y1a, y2a) && ge(std::max(y1b,y2b), std::max(y1a, y2a))) {
            //Segment<T> intersection(x1b, std::min(y1b,y2b), x2a, std::max(y1a,y2a));
            //std::cout << a << " and " << b << ": " << "Intersection segment: " << intersection << std::endl;
            return new Segment<T> (x1b, std::min(y1b,y2b), x2a, std::max(y1a,y2a));
        } else if (std::min(y1b, y2b) > std::min(y1a, y2a) && std::max(y1b,y2b) < std::max(y1a, y2a)) {
            //Segment<T> intersection(x1b, std::min(y1b,y2b), x2b, std::max(y1b,y2b));
            //std::cout << a << " and " << b << ": " << "Intersection segment: " << intersection << std::endl;
            return new Segment<T> (x1b, std::min(y1b,y2b), x2b, std::max(y1b,y2b));
        } else if (le(std::min(y1b,y2b),std::min(y1a,y2a)) && std::max(y1b,y2b)>std::min(y1a,y2a)) {
            //Segment<T> intersection(x1a, std::min(y1a,y2a), x2b, std::max(y1b,y2b));
            //std::cout << a << " and " << b << ": " << "Intersection segment: " << intersection << std::endl;
            return new Segment<T> (x1a, std::min(y1a,y2a), x2b, std::max(y1b,y2b));
        }
    } else {
        if (std::min(y1a, y2a) < std::max(y1b, y2b) && ge(std::max(y1a,y2a), std::max(y1b, y2b))) {
            //Segment<T> intersection(x1a, std::min(y1a,y2a), x2b, std::max(y1b,y2b));
            //std::cout << a << " and " << b << ": " << "Intersection segment: " << intersection << std::endl;
            return new Segment<T> (x1a, std::min(y1a,y2a), x2b, std::max(y1b,y2b));
        } else if (std::min(y1a, y2a) > std::min(y1b, y2b) && std::max(y1a,y2a) < std::max(y1b, y2b)) {
            //Segment<T> intersection(x1a, std::min(y1a,y2a), x2a, std::max(y1a,y2a));
            //std::cout << a << " and " << b << ": " << "Intersection segment: " << intersection << std::endl;
            return new Segment<T> (x1a, std::min(y1a,y2a), x2a, std::max(y1a,y2a));
        } else if (le(std::min(y1a,y2a), std::min(y1b,y2b)) && std::max(y1a,y2a)>std::min(y1b,y2b)) {
            //Segment<T> intersection(x1b, std::min(y1b,y2b), x2a, std::max(y1a,y2a));
            //std::cout << a << " and " << b << ": " << "Intersection segment: " << intersection << std::endl;
            return new Segment<T> (x1b, std::min(y1b,y2b), x2a, std::max(y1a,y2a));
        }
    }

    return new NullShape<T> ();
}



#endif // SEGMENT_H
