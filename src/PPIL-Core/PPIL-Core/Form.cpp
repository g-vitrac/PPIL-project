#include "Form.h"

const double Form::getArea()
{
	return _area;
}

const double Form::getPerimeter()
{
	return _perimeter;
}

const int Form::getColor()
{
	return _color;
}

ostream& Form::afficher(ostream& o) const
{
	return o << "Form (Color = " << _color << ")";
}

ostream& operator<<(ostream& o, const Form& c)
{
	return c.afficher(o);
}
