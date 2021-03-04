#pragma once
#include "Form.h"

class Circle : public Form
{
private:
	Vector2D _center;
	double _radius;

public:
	explicit Circle(const Vector2D& center, const double& radius, const Color& color = Color()) : _center(center), _radius(radius), Form(color) { if (radius <= 0) throw Error("Circle radius wrong"); }

	const Vector2D getCenter() const { return _center; }
	const double getRadius() const { return _radius; }

	virtual const double calculateArea() const { return M_PI * _radius * _radius; }
	virtual const double calculatePerimeter() const { return 2 * M_PI * _radius; }
	virtual const Vector2D calculateGravityVector2D() const { return _center; }
	virtual const Vector2D calculateWindowSize() const { return (_center + _radius) * 2; }

	virtual void translate(const Vector2D& vec) { _center += vec; }
	virtual void rotate(const double& radian, const Vector2D& center = Vector2D(0, 0));
	virtual void homothety(const double& zoom, const Vector2D& center = Vector2D(0, 0)) { _center = ((_center - center) * zoom) + center, _radius *= zoom; }

	virtual Form* clone() const { return new Circle(*this); }

	virtual void draw(const VDraw* visitor, const string& color) const;
	virtual void save(VSave* visitor) const;

	virtual operator string() const { ostringstream o; o << "Circle (" << Form::operator string() << "\n         center = " << _center << "\n         radius = " << _radius << ")"; return o.str(); }
};

