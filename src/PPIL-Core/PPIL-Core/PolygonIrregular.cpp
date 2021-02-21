#include "PolygonIrregular.h"

ostream& PolygonIrregular::display(ostream& o) const
{
	o << "PolygonIrregular (";
	Form::display(o);
	return o << ")";
}
