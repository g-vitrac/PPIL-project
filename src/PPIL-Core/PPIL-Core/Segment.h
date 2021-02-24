#pragma once
#include "Form.h"
#include "Vecteur2D.h"

class Segment : public Form
{
	Vecteur2D _vecA;
	Vecteur2D _vecB;

public:
	explicit Segment(Vecteur2D VA, Vecteur2D VB, string color = BLACK) : _vecA(VA), _vecB(VB), Form(color) {}

	const Vecteur2D getVecA() const { return _vecA; }
	const Vecteur2D getVecB() const { return _vecB; }

	virtual const double calculateArea() const { return 0; }
	virtual const double calculatePerimeter() const { return 0; }
	virtual const Vecteur2D calculateGravityVecteur2D() const { return (_vecA + _vecB) / 2; }
	virtual const double calculateWindowSize(Vecteur2D centerWindow) const { return max(_vecA.distance(centerWindow), _vecB.distance(centerWindow)) * 2; }

	virtual void draw(Visitor* visitor);

	virtual Form* translate(Vecteur2D vec) { return new Segment(_vecA + vec, _vecB + vec, _color); }
	virtual Form* rotate(double degrees, Vecteur2D center = Vecteur2D(0, 0));
	virtual Form* homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0)) { return new Segment((_vecA * zoom) - center, (_vecB * zoom) - center, _color); }

	virtual Form* clone() const { return new Segment(*this); }

	virtual ostream& display(ostream& o) const;
};

