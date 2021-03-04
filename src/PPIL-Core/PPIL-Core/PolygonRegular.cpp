#include "PolygonRegular.h"


PolygonRegular::PolygonRegular(const Vector2D& centerVecteur2D, const double& radius, int numberSide, const Color& color) : PolygonConvex(color)
{
	//TODO, Comment faire ?
	for (int i = 0; i < numberSide; i++) {
		_formVecteur2D.push_back(Vector2D(0, 0));
	}
}