#include "PolygonRegular.h"


PolygonRegular::PolygonRegular(Vector2D centerVecteur2D, double radius, int numberSide, string color) : PolygonConvex(color)
{
	//TODO, Comment faire ?
	for (int i = 0; i < numberSide; i++) {
		_formVecteur2D.push_back(Vector2D(0, 0));
	}
}