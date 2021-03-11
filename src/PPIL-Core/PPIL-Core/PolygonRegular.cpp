#include "PolygonRegular.h"
#include "VSave.h"

PolygonRegular::PolygonRegular(const Vector2D& centerVecteur2D, const double& radius, int numberSide, const Color& color) : PolygonConvex(color)
{
	if (numberSide < 3) throw Error("PolygonRegular : side < 3");
	double degrees = 360 / numberSide;
	double rotate = 0;
	double radian = 0;
	Vector2D base = centerVecteur2D + radius * Vector2D(1, 1);
	Vector2D round = base;
	for (int i = 0; i < numberSide; i++) {
		rotate += degrees;
		Matrix22 matrix(rotate * (Form::M_PI / 180));
		round = (matrix * (base - centerVecteur2D)) + centerVecteur2D;
		_formVecteur2D.push_back(round);
	}
}

PolygonRegular::PolygonRegular(vector<Vector2D> formVector2D, const Color& color) : PolygonConvex(formVector2D, color)
{
	Vector2D center = this->calculateGravityVector2D();
	double distance = center.distance(formVector2D[0]);
	for (unsigned int i = 1; i < formVector2D.size(); i++) {
		//Difficle de comparer 2 double
		//if (center.distance(formVector2D[i]) != distance) throw Error("PolygonRegular : PolygonG isn't regular");
	}
}

void PolygonRegular::save(VSave* visitor) const
{
	visitor->save(this);
}
