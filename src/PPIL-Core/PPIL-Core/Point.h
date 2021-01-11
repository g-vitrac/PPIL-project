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

	double getPosX() const;
	double getPosY() const;

	virtual Form* clone() const;

	bool operator == (const Point & p);
	virtual ostream& display(ostream& o) const;
};

