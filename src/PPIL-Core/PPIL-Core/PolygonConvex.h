#pragma once
#include "PolygonG.h"

class PolygonConvex : public PolygonG
{
public:
	PolygonConvex(const Color& color = Color()) : PolygonG(color) {}
	PolygonConvex(vector<Vector2D> formVector2D, const Color& color = Color()) : PolygonG(formVector2D, color) {}

	virtual const double calculateArea() const;

	virtual Form* clone() const { return new PolygonConvex(*this); }

	virtual void save(VSave* visitor) const;

	virtual operator string() const { ostringstream o; o << "PolygonConvex (" << PolygonG::operator string() << ")"; return o.str(); }
};

