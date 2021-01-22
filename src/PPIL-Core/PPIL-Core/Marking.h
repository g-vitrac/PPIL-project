#pragma once
#include "Vecteur2D.h"

class Marking
{
private:
	Vecteur2D _centerVecteur2D;
	double _radiant;
	double _lambda;

public:
	Marking(Vecteur2D centerVecteur2D);
	Marking(Vecteur2D centerVecteur2D, double radiant);
	~Marking();

	const Vecteur2D getCenterVecteur2D() const;
	const double getRadiant() const;
	const double getLambda() const;

	//Marking* clone() const;
};
extern ostream& operator<<(ostream& o, const Marking& c);

