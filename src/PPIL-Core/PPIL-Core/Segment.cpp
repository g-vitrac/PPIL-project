#include "Segment.h"

Segment::Segment(int color, Point* pointA, Point* pointB)
{
    _color = color;
    _pointA = (Point*)pointA->clone();
    _pointB = (Point*)pointB->clone();
    _gravityMarking = calculateGravityMarking(getCollectionPointsToGravity());
}

Segment::~Segment()
{
    delete _pointA;
    delete _pointB;
}

Point* Segment::getPointA() const
{
    return _pointA;
}

Point* Segment::getPointB() const
{
    return _pointB;
}

const vector<Point*> Segment::getCollectionPointsToGravity() const
{
    vector<Point*> collectionPoints;
    collectionPoints.push_back(_pointA);
    collectionPoints.push_back(_pointB);
    return collectionPoints;
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
    Form1D::afficher(o);
    return o << "\n         point A = " << *_pointA << ",\n         point B = " << *_pointB << ")";
}
