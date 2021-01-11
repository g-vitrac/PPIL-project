#pragma once
#include "Polygon.h"
class PolygonRegular : public Polygon
{
public:
	const bool isPolygonRegular() const;

	virtual const double calculateArea() const;

	virtual ostream& display(ostream& o) const;
};

