#include "Circle.h"

Circle::Circle(Point centerPoint, double radius, int color)
{
	_color = color;
	_radius = radius;
	_formPoints.push_back(centerPoint);
	_area = calculateArea();
	_perimeter = calculatePerimeter();
	_gravityPoint = calculateGravityPoint();
}

Circle::~Circle()
{
}

const double Circle::getRadius() const
{
	return _radius;
}

double const Circle::calculateArea() const
{
	return _PI * _radius * _radius;
}

double const Circle::calculatePerimeter() const
{
	return 2 * _PI * _radius;
}

/*
Form* Circle::clone() const
{
	Circle* circle = new Circle(*this);
	circle->_centerPoint = (Point*)this->_centerPoint->clone();
	return circle;
}
*/

ostream& Circle::display(ostream& o) const
{
	o << "Circle (";
	FormND::display(o);
	return o << "\n      radius = " << _radius << ", area = " << _area << ", perimeter = " << _perimeter << ")";
}
