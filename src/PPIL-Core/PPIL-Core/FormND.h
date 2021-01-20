#pragma once
#include "Form.h"
#include "Marking.h"
#include "Point.h"

class FormND : public Form
{
protected:
	double _area;
	double _perimeter;
	vector<Point> _formPoints;
	//Marking* _anchorMarking;
	Point _gravityPoint;

public:	
	const double getArea() const;
	const double getPerimeter() const;
	//Marking* getAnchorMarking() const;
	Point getGravityPoint() const;
	Point getPointToFormPoints(int index);

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	Point calculateGravityPoint();

	virtual ostream& display(ostream& o) const;
};

