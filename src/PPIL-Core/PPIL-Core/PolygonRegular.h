#pragma once
#include "Form.h"

class PolygonRegular : public Form
{
public:
	PolygonRegular(Vecteur2D centerVecteur2D, double radius, int numberSide, int color);
	~PolygonRegular();

	//const bool isPolygonRegular() const;

	virtual const double calculateArea() const;

	virtual ostream& display(ostream& o) const;
};

