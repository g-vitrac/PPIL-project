#pragma once
#include "Form.h"

class Polygon : public Form
{
protected:
	vector<Vector2D> _formVecteur2D;

public:
	Polygon(string color = BLACK) : Form(color) {}
	Polygon(vector<Vector2D> formVecteur2D, string color = BLACK);

	virtual const double calculatePerimeter() const;
	virtual const Vector2D calculateGravityVector2D() const;
	virtual const Vector2D calculateWindowSize() const { return Vector2D(); }

	virtual Form* translate(Vector2D vec);
	virtual Form* homothety(double zoom, Vector2D center = Vector2D(0, 0));

	virtual operator string() const;
};

