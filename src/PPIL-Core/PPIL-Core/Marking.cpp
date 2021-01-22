#include "Marking.h"

Marking::Marking(Vecteur2D centerVecteur2D)
{
	_centerVecteur2D = centerVecteur2D;
	_radiant = 0;
}

Marking::Marking(Vecteur2D centerVecteur2D, double radiant)
{
	_centerVecteur2D = centerVecteur2D;
	_radiant = radiant;
}

Marking::~Marking()
{
}

const Vecteur2D Marking::getCenterVecteur2D() const
{
	return _centerVecteur2D;
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
	marking->_centerVecteur2D = (Vecteur2D*)this->_centerVecteur2D->clone();
	return marking;
}
*/

ostream& operator<<(ostream& o, const Marking& c)
{
	return o << "Marking (" << "center Vecteur2D = " << c.getCenterVecteur2D() << ", radiant = " << c.getRadiant();
}
