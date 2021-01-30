#pragma once
#include "Form.h"

class Polygon : public Form
{
public:
	Polygon(int color = BLACK);
	Polygon(vector<Vecteur2D> formVecteur2D, int color = BLACK);
	~Polygon();

	virtual const double calculatePerimeter() const;

	virtual ostream& display(ostream& o) const;
};

