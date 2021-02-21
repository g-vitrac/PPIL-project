#pragma once
#include "Polygon.h"

class PolygonConvex : public Polygon
{
public:
	PolygonConvex(string color = BLACK) : Polygon(color) {}
	PolygonConvex(vector<Vecteur2D> formVecteur2D, string color = BLACK) : Polygon(formVecteur2D, color) {}

	virtual const double calculateArea() const;

	virtual void draw(Visitor* visitor);

	virtual ostream& display(ostream& o) const;
};

