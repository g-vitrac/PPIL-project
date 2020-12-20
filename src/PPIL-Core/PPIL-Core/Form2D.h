#pragma once
#include "FormND.h"

class Form2D : public FormND
{
protected:
	double _area;
	double _perimeter;

public:
	const double getArea();
	const double getPerimeter();
	const int getColor();

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	virtual Form* clone() const = 0;

	virtual ostream& afficher(ostream& o) const;
};

