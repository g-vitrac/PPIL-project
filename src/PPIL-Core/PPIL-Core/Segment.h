#pragma once
#include "Form1D.h"
#include "Point.h"

class Segment : public Form1D
{
private:
	Point* _pointA;
	Point* _pointB;

public:
	Segment(int color, Point* pointA, Point* pointB);
	~Segment();

	Point * getPointA() const;
	Point * getPointB() const;

	virtual const vector<Point*> getCollectionPointsToGravity() const;
	virtual Form* clone() const;

	virtual ostream& afficher(ostream& o) const;
};

