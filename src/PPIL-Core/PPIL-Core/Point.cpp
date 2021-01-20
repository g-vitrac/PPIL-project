#include "Point.h"

Point::Point()
{
    _color = 0;
    _posX = 0;
    _posY = 0;
}

Point::Point(double posX, double posY, int color)
{
    _color = color;
    _posX = posX;
    _posY = posY;
}

Point::Point(const Point& p)
{
    _color = p._color;
    _posX = p._posX;
    _posY = p._posY;
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

/*
Form* Point::clone() const
{
    return new Point(*this);
}
*/

Point& Point::operator=(const Point& p)
{
    if (this != &p) {
        this->_posX = p._posX;
        this->_posY = p._posY;
    }
    return *this;
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
