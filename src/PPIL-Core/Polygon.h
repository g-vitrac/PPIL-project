#pragma once
#include "Form.h"

class Polygon : public Form
{
protected:
	vector<Vecteur2D> _formVecteur2D;

public:
	Polygon(int color = BLACK) : Form(color) {}
	Polygon(vector<Vecteur2D> formVecteur2D, int color = BLACK);

	virtual const double calculatePerimeter() const;
	virtual const Vecteur2D calculateGravityVecteur2D() const;

	virtual void translate(Vecteur2D vec);
	virtual void homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0));

	virtual ostream& display(ostream& o) const;
};

