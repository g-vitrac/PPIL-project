#pragma once
#include "FormDimension.h"
#include "Point.h"

class Circle : public FormDimension
{
private:
	const double _PI = 3.1415;
	Point* _centerPoint;
	double _radius;

public:

	Circle(int color, Point* centerPoint, double radius);
	~Circle();
	
	const Point* getCenterPoint() const;
	const double getRadius() const;

	virtual double const calculateArea() const;
	virtual double const calculatePerimeter() const;
	virtual Form* clone() const;

	virtual ostream& afficher(ostream& o) const;
};

