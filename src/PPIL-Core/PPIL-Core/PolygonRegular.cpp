#include "PolygonRegular.h"
#include "VSave.h"

PolygonRegular::PolygonRegular(const Vector2D& centerVecteur2D, const double& radius, int numberSide, const Color& color) : PolygonConvex(color)
{
	//TODO, Comment faire ?
	for (int i = 0; i < numberSide; i++) {
		_formVecteur2D.push_back(Vector2D(0, 0));
	}
}

PolygonRegular::PolygonRegular(vector<Vector2D> formVector2D, const Color& color) : PolygonConvex(formVector2D, color)
{
	Vector2D center = this->calculateGravityVector2D();
	double distance = center.distance(formVector2D[0]);
	for (unsigned int i = 1; i < formVector2D.size(); i++) {
		if (center.distance(formVector2D[i]) != distance) throw Error("PolygonRegular : PolygonG isn't regular");
	}
}

void PolygonRegular::save(VSave* visitor) const
{
	visitor->save(this);
}
