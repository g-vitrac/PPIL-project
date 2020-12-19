#pragma once
#include "Form.h"

class Point : public Form
{
private:
	double _posX;
	double _posY;

public:
	Point(int color, double posX, double posY);
	~Point();

	const double getPosX() const;
	const double getPosY() const;

	virtual double const calculateArea() const;
	virtual double const calculatePerimeter() const;
	virtual Form* clone() const;

	virtual ostream& afficher(ostream& o) const;
};

