#include "Circle.h"
#include "Visitor.h"

Form* Circle::rotate(double degrees, Vector2D center)
{
	double radiant = degrees * M_PI / 180;
	double vcos = cos(radiant);
	double vsin = sin(radiant);
	_center = _center - center;
	Vector2D A(_center.getPosX() * vcos - _center.getPosY() * vsin, _center.getPosX() * vsin + _center.getPosY() * vcos);
	return new Circle(A + center, _radius, _color);
}

void Circle::draw(Visitor* visitor, const string& color) const
{
	visitor->draw(this, color);
}

ostream& Circle::display(ostream& o) const
{
	o << "Circle (";
	Form::display(o);
	o << "\n         - " << _center;
	return o << "\n      radius = " << _radius << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ")";
}
