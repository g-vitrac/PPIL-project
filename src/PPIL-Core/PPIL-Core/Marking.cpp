#include "Marking.h"

Marking::Marking(Point centerPoint)
{
	_centerPoint = centerPoint;
	_radiant = 0;
}

Marking::Marking(Point centerPoint, double radiant)
{
	_centerPoint = centerPoint;
	_radiant = radiant;
}

Marking::~Marking()
{
}

const Point Marking::getCenterPoint() const
{
	return _centerPoint;
}

const double Marking::getRadiant() const
{
	return _radiant;
}

const double Marking::getLambda() const
{
	return _lambda;
}

/*
Marking* Marking::clone() const
{
	Marking* marking = new Marking(*this);
	marking->_centerPoint = (Point*)this->_centerPoint->clone();
	return marking;
}
*/

ostream& operator<<(ostream& o, const Marking& c)
{
	return o << "Marking (" << "center point = " << c.getCenterPoint() << ", radiant = " << c.getRadiant();
}
