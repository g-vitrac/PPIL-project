#pragma once
#include "PolygonConvex.h"

class PolygonRegular : public PolygonConvex
{
public:
	PolygonRegular(Vector2D centerVector2D, double radius, int numberSide, string color = BLACK);
	~PolygonRegular();

	virtual ostream& display(ostream& o) const;
};

