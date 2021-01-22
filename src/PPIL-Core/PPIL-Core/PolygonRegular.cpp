#include "PolygonRegular.h"


PolygonRegular::PolygonRegular(Vecteur2D centerVecteur2D, double radius, int numberSide, int color)
{
	//TODO, Il faut implementer les forumules vectorielles dans Vecteur2D pour calculer la distance à partir d'un diametre
	for (int i = 0; i < numberSide; i++) {
		_formVecteur2D.push_back(Vecteur2D(0, 0, color));
	}
}

const double PolygonRegular::calculateArea() const
{
	//TODO, Il faut implementer les forumules vectorielles dans Vecteur2D pour calculer la distance
	//double apothem = _collectionSegments[0]->calculateDistance() / (2 * tan(180 / _collectionSegments.size()));
	double apothem = 0;
	return (apothem * _perimeter) / 2;
}

ostream& PolygonRegular::display(ostream& o) const
{
	o << "PolygonRegular (";
	Form::display(o);
	return o << ")";
}
