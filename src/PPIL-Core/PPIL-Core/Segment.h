#pragma once
#include "Form.h"
#include "Vector2D.h"

class Segment : public Form
{
	Vector2D _vecA;
	Vector2D _vecB;

public:
	explicit Segment(Vector2D VA, Vector2D VB, string color = BLACK) : _vecA(VA), _vecB(VB), Form(color) {}

	const Vector2D getVecA() const { return _vecA; }
	const Vector2D getVecB() const { return _vecB; }

	virtual const double calculateArea() const { return 0; }
	virtual const double calculatePerimeter() const { return 0; }
	virtual const Vector2D calculateGravityVector2D() const { return (_vecA + _vecB) / 2; }
	virtual const Vector2D calculateWindowSize() const { return _vecA.maximum(_vecB) * 2; }

	virtual Form* translate(Vector2D vec) { return new Segment(_vecA + vec, _vecB + vec, _color); }
	virtual Form* rotate(double degrees, Vector2D center = Vector2D(0, 0));
	virtual Form* homothety(double zoom, Vector2D center = Vector2D(0, 0)) { return new Segment(((_vecA - center) * zoom) + center, ((_vecB - center) * zoom) + center); }

	virtual Form* clone() const { return new Segment(*this); }

	virtual void draw(VDraw* visitor, const string& color) const;
	virtual void save(VSave* visitor) const;

	virtual operator string() const { ostringstream o; o << "Segment (" << Form::operator string() << "\n         vector 1 = " << _vecA << "\n         vector 2 = " << _vecB << ")"; return o.str(); }
};

