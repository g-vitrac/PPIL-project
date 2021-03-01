#pragma once
#include "Form.h"
#include "Vector2D.h"

class Circle : public Form
{
private:
	Vector2D _center;
	double _radius;

public:
	explicit Circle(Vector2D center, double radius, string color = BLACK) : _center(center), _radius(radius), Form(color) {}

	const Vector2D getCenter() const { return _center; }
	const double getRadius() const { return _radius; }

	virtual const double calculateArea() const { return M_PI * _radius * _radius; }
	virtual const double calculatePerimeter() const { return 2 * M_PI * _radius; }
	virtual const Vector2D calculateGravityVector2D() const { return _center; }
	virtual const Vector2D calculateWindowSize() const { return (_center + _radius) * 2; }

	virtual Form* translate(Vector2D vec) { return new Circle(_center + vec, _radius, _color); }
	virtual Form* rotate(double degrees, Vector2D center = Vector2D(0, 0));
	virtual Form* homothety(double zoom, Vector2D center = Vector2D(0, 0)) { return new Circle(((_center - center) * zoom) + center, _radius * zoom, _color); }

	virtual Form* clone() const { return new Circle(*this); }

	virtual void draw(VDraw* visitor, const string& color) const;
	virtual void save(VSave* visitor) const;

	virtual operator string() const { ostringstream o; o << "Circle (" << Form::operator string() << "\n         center = " << _center << "\n         radius = " << _radius << ")"; return o.str(); }
};

