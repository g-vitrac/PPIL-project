#include "Circle.h"
#include "Visitor.h"

Circle::Circle(Vecteur2D centerVecteur2D, double radius, int color) : Form(color)
{
	_radius = radius;
	_formVecteur2D.push_back(centerVecteur2D);
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
	circle->_centerVecteur2D = (Vecteur2D*)this->_centerVecteur2D->clone();
	return circle;
}
*/

void Circle::draw(Visitor* visitor)
{
	visitor->draw(this);
}

ostream& Circle::display(ostream& o) const
{
	o << "Circle (";
	Form::display(o);
	return o << "\n      radius = " << _radius << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ")";
}
