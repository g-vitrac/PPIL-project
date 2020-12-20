#include "PolygonRegular.h"

const double PolygonRegular::calculateArea() const
{
	return 0;
}

ostream& PolygonRegular::afficher(ostream& o) const
{
	o << "PolygonRegular (";
	Polygon::afficher(o);
	return o << ")";
}
