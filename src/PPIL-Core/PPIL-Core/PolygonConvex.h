#pragma once
#include "Polygon.h"

class PolygonConvex : public Polygon
{
public:
	PolygonConvex(const Color& color = Color()) : Polygon(color) {}
	PolygonConvex(vector<Vector2D> formVector2D, const Color& color = Color()) : Polygon(formVector2D, color) {}

	virtual const double calculateArea() const;

	virtual Form* clone() const { return new PolygonConvex(*this); }

	virtual void draw(const VDraw* visitor, const string& color) const;

	virtual operator string() const { ostringstream o; o << "PolygonConvex (" << Polygon::operator string() << ")"; return o.str(); }
};

