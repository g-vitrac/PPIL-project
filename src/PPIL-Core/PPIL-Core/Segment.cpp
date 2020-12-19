#include "Segment.h"

Segment::Segment(int color, Point* pointA, Point* pointB)
{
    _pointA = (Point*)pointA->clone();
    _pointB = (Point*)pointB->clone();
    _color = color;
    _area = calculateArea();
    _perimeter = calculatePerimeter();
}

Segment::~Segment()
{
    delete _pointA;
    delete _pointB;
}

const Point* Segment::getPointA() const
{
    return _pointA;
}

const Point* Segment::getPointB() const
{
    return _pointB;
}

double const Segment::calculateArea() const
{
    return 0;
}

double const Segment::calculatePerimeter() const
{
    return 0;
}

Form* Segment::clone() const
{
    Segment * segment = new Segment(*this);
    //Comment appeler le clone des points automatiquement ?
    segment->_pointA = (Point*)this->_pointA->clone();
    segment->_pointB = (Point*)this->_pointB->clone();
    return segment;
}

ostream& Segment::afficher(ostream& o) const
{
    o << "Segment (";
    Form::afficher(o);
    return o << "\n     point A = " << *_pointA << ",\n     point B = " << *_pointB << ",\narea = " << _area << ", perimeter = " << _perimeter << ")";
}
