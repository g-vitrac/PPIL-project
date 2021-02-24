#pragma once
#include "Form.h"

class Polygon : public Form
{
protected:
	vector<Vecteur2D> _formVecteur2D;

public:
	Polygon(string color = BLACK) : Form(color) {}
	Polygon(vector<Vecteur2D> formVecteur2D, string color = BLACK);

	virtual const double calculatePerimeter() const;
	virtual const Vecteur2D calculateGravityVecteur2D() const;
	virtual const double calculateWindowSize(Vecteur2D centerWindow) const { return 0; }

	virtual Form* translate(Vecteur2D vec);
	virtual Form* homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0));

	virtual ostream& display(ostream& o) const;
};

