#include "PolygonRegular.h"

const bool PolygonRegular::isPolygonRegular() const
{
	double distance = _collectionSegments[0]->calculateDistance();
	for (unsigned int i = 1; i < _collectionSegments.size(); i++) {
		if (_collectionSegments[i]->calculateDistance() != distance)
			return false;
	}
	return true;
}

const double PolygonRegular::calculateArea() const
{
	double apothem = _collectionSegments[0]->calculateDistance() / (2 * tan(180 / _collectionSegments.size()));
	return (apothem * _perimeter) / 2;
}

ostream& PolygonRegular::display(ostream& o) const
{
	o << "PolygonRegular (";
	Polygon::display(o);
	return o << ")";
}
