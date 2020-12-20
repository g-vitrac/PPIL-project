#pragma once
#include "Point.h"

class Marking
{
private:
	Point* _centerPoint;
	double _radiant;

public:
	Marking(Point* centerPoint);
	Marking(Point* centerPoint, double radiant);
	~Marking();

	const Point* getCenterPoint() const;
	const double getRadiant() const;

	Marking* clone() const;
};
extern ostream& operator<<(ostream& o, const Marking& c);

