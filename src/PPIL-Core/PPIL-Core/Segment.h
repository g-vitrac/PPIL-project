#pragma once
#include "Form.h"

class Segment : public Form
{
	Vector2D _vecA;
	Vector2D _vecB;

public:
	explicit Segment(const Vector2D& VA, const Vector2D& VB, const Color& color = Color()) : _vecA(VA), _vecB(VB), Form(color) {}

	const Vector2D getVecA() const { return _vecA; }
	const Vector2D getVecB() const { return _vecB; }

	virtual const double calculateArea() const { return 0; }
	virtual const double calculatePerimeter() const { return 0; }
	virtual const Vector2D calculateGravityVector2D() const { return (_vecA + _vecB) / 2; }
	virtual const Vector2D calculateWindowSize() const { return _vecA.maximum(_vecB) * 2; }

	virtual void translate(const Vector2D& vec) { _vecA += vec; _vecB += vec; }
	virtual void rotate(const double& radian, const Vector2D& center = Vector2D(0, 0));
	virtual void homothety(const double& zoom, const Vector2D& center = Vector2D(0, 0)) { _vecA = ((_vecA - center) * zoom) + center, _vecB = ((_vecB - center) * zoom) + center; }

	virtual Form* clone() const { return new Segment(*this); }

	virtual void draw(const VDraw* visitor, const string& color) const;
	virtual void save(VSave* visitor) const;

	virtual operator string() const { ostringstream o; o << "Segment (" << Form::operator string() << "\n         vector 1 = " << _vecA << "\n         vector 2 = " << _vecB << ")"; return o.str(); }
};

