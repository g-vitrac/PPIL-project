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

bool Point::operator==(const Point& p)
{
    return this->_posX == p._posX && this->_posY == p._posY;
}

ostream& Point::display(ostream& o) const
{
    o << "Point (";
    Form::display(o);
    return o << "position X = " << _posX << ", postion Y = " << _posY << ")";
}
