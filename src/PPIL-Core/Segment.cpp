#include "Segment.h"
#include "Visitor.h"

/*
Form* Segment::clone() const
{
    Segment * segment = new Segment(*this);
    //Comment appeler le clone des Vecteur2Ds automatiquement ?
    segment->_Vecteur2DA = (Vecteur2D*)this->_Vecteur2DA->clone();
    segment->_Vecteur2DB = (Vecteur2D*)this->_Vecteur2DB->clone();
    return segment;
}
*/

void Segment::draw(Visitor* visitor)
{
    visitor->draw(this);
}

void Segment::rotate(double degrees, Vecteur2D center)
{
    double radiant = degrees * M_PI / 180;
    double vcos = cos(radiant);
    double vsin = sin(radiant);
    _vecA = _vecA - center;
    _vecB = _vecB - center;
    Vecteur2D A(_vecA.getPosX() * vcos - _vecA.getPosY() * vsin, _vecA.getPosX() * vsin + _vecA.getPosY() * vcos);
    Vecteur2D B(_vecB.getPosX() * vcos - _vecB.getPosY() * vsin, _vecB.getPosX() * vsin + _vecB.getPosY() * vcos);
    _vecA = A + center;
    _vecB = B + center;
}


ostream& Segment::display(ostream& o) const
{
    o << "Segment (";
    Form::display(o);
    o << "\n         - " << _vecA;
    o << "\n         - " << _vecB;
    return o << ")";
}
