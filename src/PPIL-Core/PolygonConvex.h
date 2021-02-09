#pragma once
#include "Polygon.h"

class PolygonConvex : public Polygon
{
public:
	PolygonConvex(int color = BLACK);
	PolygonConvex(vector<Vecteur2D> formVecteur2D, int color = BLACK);
	~PolygonConvex();

	virtual const double calculateArea() const;

	virtual void draw(Visitor* visitor);

	virtual ostream& display(ostream& o) const;
};

