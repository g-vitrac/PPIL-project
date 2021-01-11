#include "PolygonIrregular.h"

ostream& PolygonIrregular::display(ostream& o) const
{
	o << "PolygonIrregular (";
	Polygon::display(o);
	return o << ")";
}
