#pragma once
#include "PolygonConvex.h"

class PolygonRegular : public PolygonConvex
{
public:
	PolygonRegular(Vector2D centerVector2D, double radius, int numberSide, string color = BLACK);

	virtual operator string() const { ostringstream o; o << "PolygonRegular (" << PolygonConvex::operator string() << ")"; return o.str(); }
};

