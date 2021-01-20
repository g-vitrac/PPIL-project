#include "Segment.h"

Segment::Segment(Point pointA, Point pointB, int color)
{
    _color = color;
    _formPoints.push_back(pointA);
    _formPoints.push_back(pointB);
    _gravityPoint = calculateGravityPoint();
}

Segment::~Segment()
{
}

double const Segment::calculateArea() const
{
    return 0;
}

double const Segment::calculatePerimeter() const
{
    return 0;
}

/*
const bool Segment::isAdjacentSides(Segment* segment)
{
    return *this->_pointA == *segment->_pointA || *this->_pointA == *segment->_pointB || *this->_pointB == *segment->_pointA || *this->_pointB == *segment->_pointB;
}

const double Segment::calculateDistance()
{
    double posX = _pointA->getPosX() - _pointB->getPosX();
    double posY = _pointA->getPosY() - _pointB->getPosY();
    return sqrt((posX * posX) + (posY * posY));
}
*/

/*
Form* Segment::clone() const
{
    Segment * segment = new Segment(*this);
    //Comment appeler le clone des points automatiquement ?
    segment->_pointA = (Point*)this->_pointA->clone();
    segment->_pointB = (Point*)this->_pointB->clone();
    return segment;
}
*/

ostream& Segment::display(ostream& o) const
{
    o << "Segment (";
    FormND::display(o);
    return o << ")";
}
