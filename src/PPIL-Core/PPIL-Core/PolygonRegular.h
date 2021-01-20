#pragma once
#include "FormND.h"

class PolygonRegular : public FormND
{
public:
	PolygonRegular(Point centerPoint, double diameter, int numberSide, int color);
	~PolygonRegular();

	//const bool isPolygonRegular() const;

	virtual const double calculateArea() const;

	virtual ostream& display(ostream& o) const;
};

