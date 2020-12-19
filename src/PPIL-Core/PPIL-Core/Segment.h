#pragma once
#include "FormDimension.h"
#include "Point.h"

class Segment : public FormDimension
{
private:
	Point* _pointA;
	Point* _pointB;

public:
	Segment(int color, Point* pointA, Point* pointB);
	~Segment();

	const Point * getPointA() const;
	const Point * getPointB() const;

	virtual double const calculateArea() const;
	virtual double const calculatePerimeter() const;
	virtual Form* clone() const;

	virtual ostream& afficher(ostream& o) const;
};

