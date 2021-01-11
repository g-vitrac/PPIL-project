#include "Form.h"

const int Form::getColor() const
{
	return _color;
}

ostream& operator<<(ostream& o, const Form& c)
{
	return c.display(o);
}

ostream& Form::display(ostream& o) const
{
	return o << "Form (color = " << _color << ")";
}