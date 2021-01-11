#include "Form2D.h"

const double Form2D::getArea() const
{
	return _area;
}

const double Form2D::getPerimeter() const
{
	return _perimeter;
}

ostream& Form2D::display(ostream& o) const
{
	o << "Form2D (";
	FormND::display(o);
	return o << "area = " << _area << ", perimeter = " << _perimeter << ")";
}
