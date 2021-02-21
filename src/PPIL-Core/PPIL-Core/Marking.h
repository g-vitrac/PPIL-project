#pragma once
#include "Vecteur2D.h"

class Marking
{
private:
	Vecteur2D _centerVecteur2D;
	double _radiant;
	double _lambda;

public:
	explicit Marking(Vecteur2D centerVecteur2D = Vecteur2D(), double radiant = 0, double lambda = 1) : _centerVecteur2D(centerVecteur2D), _radiant(radiant), _lambda(lambda) {}

	const Vecteur2D getCenterVecteur2D() const { return _centerVecteur2D; }
	const double getRadiant() const { return _radiant; }
	const double getLambda() const { return _lambda; }

	void setCenterVecteur2D(Vecteur2D centerVecteur2D) { _centerVecteur2D = centerVecteur2D; }
	void setRadiant(double radiant) { _radiant = radiant; }
	void setLambda(double lambda) { _lambda = lambda; }

	operator string() const { ostringstream o; o << "Marking (" << "center Vecteur2D = " << _centerVecteur2D << ", radiant = " << _radiant << ", lambda = " << _lambda; return o.str(); }
};
inline ostream& operator<<(ostream& o, const Marking& m) { return o << (string)m; }

