#pragma once
#include "Form.h"

class Point : public Form
{
private:
	double _posX;
	double _posY;

public:
	Point();
	Point(double posX, double posY, int color);
	Point(const Point & p);
	~Point();

	double getPosX() const;
	double getPosY() const;

	//virtual Form* clone() const;

	Point & operator=(const Point & p);
	bool operator == (const Point & p);
	virtual ostream& display(ostream& o) const;
};

