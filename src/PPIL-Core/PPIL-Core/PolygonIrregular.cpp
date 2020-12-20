#include "PolygonIrregular.h"

ostream& PolygonIrregular::afficher(ostream& o) const
{
	o << "PolygonIrregular (";
	Polygon::afficher(o);
	return o << ")";
}
