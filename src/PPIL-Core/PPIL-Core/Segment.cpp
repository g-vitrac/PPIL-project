#include "Segment.h"
#include "Visitor.h"

void Segment::draw(Visitor* visitor)
{
    visitor->draw(this);
}

Form* Segment::rotate(double degrees, Vecteur2D center)
{
    double radiant = degrees * M_PI / 180;
    double vcos = cos(radiant);
    double vsin = sin(radiant);
    _vecA = _vecA - center;
    _vecB = _vecB - center;
    Vecteur2D A(_vecA.getPosX() * vcos - _vecA.getPosY() * vsin, _vecA.getPosX() * vsin + _vecA.getPosY() * vcos);
    Vecteur2D B(_vecB.getPosX() * vcos - _vecB.getPosY() * vsin, _vecB.getPosX() * vsin + _vecB.getPosY() * vcos);
    return new Segment(A + center, B + center, _color);
}


ostream& Segment::display(ostream& o) const
{
    o << "Segment (";
    Form::display(o);
    o << "\n         - " << _vecA;
    o << "\n         - " << _vecB;
    return o << ")";
}
