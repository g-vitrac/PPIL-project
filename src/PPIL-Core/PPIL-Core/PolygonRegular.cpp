#include "PolygonRegular.h"

/*
const bool PolygonRegular::isPolygonRegular() const
{
	double distance = _collectionSegments[0]->calculateDistance();
	for (unsigned int i = 1; i < _collectionSegments.size(); i++) {
		if (_collectionSegments[i]->calculateDistance() != distance)
			return false;
	}
	return true;
}
*/

PolygonRegular::PolygonRegular(Point centerPoint, double diameter, int numberSide, int color)
{
	//TODO, Il faut implementer les forumules vectorielles dans point pour calculer la distance à partir d'un diametre
	for (int i = 0; i < numberSide; i++) {
		_formPoints.push_back(Point(0, 0, color));
	}
}

PolygonRegular::~PolygonRegular()
{
}

const double PolygonRegular::calculateArea() const
{
	//TODO, Il faut implementer les forumules vectorielles dans point pour calculer la distance
	//double apothem = _collectionSegments[0]->calculateDistance() / (2 * tan(180 / _collectionSegments.size()));
	double apothem = 0;
	return (apothem * _perimeter) / 2;
}

ostream& PolygonRegular::display(ostream& o) const
{
	o << "PolygonRegular (";
	FormND::display(o);
	return o << ")";
}
