#pragma once
#include "FormND.h"
#include "Point.h"

class Circle : public FormND
{
private:
	const double _PI = 3.1415;
	double _radius;

public:
	Circle(Point centerPoint, double radius, int color);
	~Circle();
	
	const double getRadius() const;

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	//virtual Form* clone() const;

	virtual ostream& display(ostream& o) const;
};

