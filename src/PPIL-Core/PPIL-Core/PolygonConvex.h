#pragma once
#include "Polygon.h"

class PolygonConvex : public Polygon
{
public:
	PolygonConvex(string color = BLACK) : Polygon(color) {}
	PolygonConvex(vector<Vector2D> formVector2D, string color = BLACK) : Polygon(formVector2D, color) {}

	virtual const double calculateArea() const;

	virtual void draw(VDraw* visitor);

	virtual operator string() const { ostringstream o; o << "PolygonConvex (" << Polygon::operator string() << ")"; return o.str(); }
};

