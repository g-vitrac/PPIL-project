#include "Form.h"

ostream& Form::afficher(ostream& o) const
{
	return o << "Form (Color = " << _color << ")";
}

ostream& operator<<(ostream& o, const Form& c)
{
	return c.afficher(o);
}
