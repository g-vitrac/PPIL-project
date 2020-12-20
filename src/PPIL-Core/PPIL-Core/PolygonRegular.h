#pragma once
#include "Polygon.h"
class PolygonRegular : public Polygon
{
public:
	virtual const double calculateArea() const;

	virtual ostream& afficher(ostream& o) const;
};

