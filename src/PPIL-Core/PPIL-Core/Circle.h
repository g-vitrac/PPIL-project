#pragma once
#include "Form2D.h"
#include "Point.h"

class Circle : public Form2D
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

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	virtual const vector<Point*> getCollectionPointsToGravity() const;
	virtual Form* clone() const;

	virtual ostream& display(ostream& o) const;
};

