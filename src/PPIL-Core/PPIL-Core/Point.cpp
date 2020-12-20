#include "Point.h"

Point::Point(int color, double posX, double posY)
{
    _color = color;
    _posX = posX;
    _posY = posY;
}

Point::~Point()
{
}

double Point::getPosX() const
{
    return _posX;
}

double Point::getPosY() const
{
    return _posY;
}

Form* Point::clone() const
{
    return new Point(*this);
}

ostream& Point::afficher(ostream& o) const
{
    o << "Point (";
    Form::afficher(o);
    return o << "position X = " << _posX << ", postion Y = " << _posY << ")";
}
