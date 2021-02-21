#include "Circle.h"
#include "Visitor.h"

/*
Form* Circle::clone() const
{
	Circle* circle = new Circle(*this);
	circle->_centerVecteur2D = (Vecteur2D*)this->_centerVecteur2D->clone();
	return circle;
}
*/

Form* Circle::rotate(double degrees, Vecteur2D center)
{
	double radiant = degrees * M_PI / 180;
	double vcos = cos(radiant);
	double vsin = sin(radiant);
	_center = _center - center;
	Vecteur2D A(_center.getPosX() * vcos - _center.getPosY() * vsin, _center.getPosX() * vsin + _center.getPosY() * vcos);
	return new Circle(A + center, _radius, _color);
}

void Circle::draw(Visitor* visitor)
{
	visitor->draw(this);
}

ostream& Circle::display(ostream& o) const
{
	o << "Circle (";
	Form::display(o);
	o << "\n         - " << _center;
	return o << "\n      radius = " << _radius << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ")";
}
