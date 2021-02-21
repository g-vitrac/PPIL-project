#include "PolygonRegular.h"


PolygonRegular::PolygonRegular(Vecteur2D centerVecteur2D, double radius, int numberSide, string color) : PolygonConvex(color)
{
	//TODO, Comment faire ?
	for (int i = 0; i < numberSide; i++) {
		_formVecteur2D.push_back(Vecteur2D(0, 0));
	}
}

PolygonRegular::~PolygonRegular()
{
}

ostream& PolygonRegular::display(ostream& o) const
{
	o << "PolygonRegular (";
	PolygonConvex::display(o);
	return o << ")";
}
