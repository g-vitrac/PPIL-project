#include "Form1D.h"

ostream& Form1D::afficher(ostream& o) const
{
	o << "Form1D (";
	FormND::afficher(o);
	return o << ")";
}
