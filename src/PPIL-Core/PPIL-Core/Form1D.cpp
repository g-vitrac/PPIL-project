#include "Form1D.h"

ostream& Form1D::display(ostream& o) const
{
	o << "Form1D (";
	FormND::display(o);
	return o << ")";
}
