#pragma once
#include "PolygonConvex.h"

class PolygonRegular : public PolygonConvex
{
public:
	PolygonRegular(Vecteur2D centerVecteur2D, double radius, int numberSide, int color = BLACK);
	~PolygonRegular();

	virtual ostream& display(ostream& o) const;
};
