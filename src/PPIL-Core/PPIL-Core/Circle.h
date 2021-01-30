#pragma once
#include "Form.h"
#include "Vecteur2D.h"

class Circle : public Form
{
private:
	const double _PI = 3.1415;
	double _radius;

public:
	Circle(Vecteur2D centerVecteur2D, double radius, int color);
	~Circle();
	
	const double getRadius() const;

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	//virtual Form* clone() const;

	virtual void draw(Visitor* visitor);

	virtual ostream& display(ostream& o) const;
};

