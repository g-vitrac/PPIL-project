#pragma once
#include "FormND.h"
#include "Point.h"

class Segment : public FormND
{
public:
	Segment(Point pointA, Point pointB, int color);
	~Segment();

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	//const bool isAdjacentSides(Segment* segment);
	//const double calculateDistance();

	//virtual Form* clone() const;

	virtual ostream& display(ostream& o) const;
};

