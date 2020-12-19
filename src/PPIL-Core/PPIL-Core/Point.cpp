#include "Point.h"

Point::Point(int color, double posX, double posY)
{
    _posX = posX;
    _posY = posY;
    _color = color;
    _area = calculateArea();
    _perimeter = calculatePerimeter();
}

Point::~Point()
{
}

const double Point::getPosX() const
{
    return _posX;
}

const double Point::getPosY() const
{
    return _posY;
}

double const Point::calculateArea() const
{
    return 0;
}

double const Point::calculatePerimeter() const
{
    return 0;
}

Form* Point::clone() const
{
    return new Point(*this);
}

ostream& Point::afficher(ostream& o) const
{
    o << "Point (";
    Form::afficher(o);
    return o << "position X = " << _posX << ", postion Y = " << _posY << ", area = " << _area << ", perimeter = " << _perimeter << ")";
}
