#include "Form2D.h"

const double Form2D::getArea()
{
	return _area;
}

const double Form2D::getPerimeter()
{
	return _perimeter;
}

const int Form2D::getColor()
{
	return _color;
}

ostream& Form2D::afficher(ostream& o) const
{
	o << "Form2D (";
	FormND::afficher(o);
	return o << ")";
}
