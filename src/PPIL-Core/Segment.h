#pragma once
#include "Form.h"
#include "Vecteur2D.h"

class Segment : public Form
{
	Vecteur2D _vecA;
	Vecteur2D _vecB;

public:
	explicit Segment(Vecteur2D VA, Vecteur2D VB, int color = BLACK) : _vecA(VA), _vecB(VB), Form(color) {}

	const Vecteur2D getVecA() const { return _vecA; }
	const Vecteur2D getVecB() const { return _vecB; }

	virtual const double calculateArea() const { return 0; }
	virtual const double calculatePerimeter() const { return 0; }
	virtual const Vecteur2D calculateGravityVecteur2D() const { return (_vecA + _vecB) / 2; }

	virtual void draw(Visitor* visitor);

	virtual void translate(Vecteur2D vec) { _vecA = _vecA + vec; _vecB = _vecB + vec; }
	virtual void rotate(double degrees, Vecteur2D center = Vecteur2D(0, 0));
	virtual void homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0)) { _vecA = (_vecA * zoom) - center; _vecB = (_vecB * zoom) - center; }

	//virtual Form* clone() const;

	virtual ostream& display(ostream& o) const;
};

