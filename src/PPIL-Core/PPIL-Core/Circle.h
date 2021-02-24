#pragma once
#include "Form.h"
#include "Vecteur2D.h"

class Circle : public Form
{
private:
	Vecteur2D _center;
	double _radius;

public:
	explicit Circle(Vecteur2D center, double radius, string color = BLACK) : _center(center), _radius(radius), Form(color) {}

	const Vecteur2D getCenter() const { return _center; }
	const double getRadius() const { return _radius; }

	virtual const double calculateArea() const { return M_PI * _radius * _radius; }
	virtual const double calculatePerimeter() const { return 2 * M_PI * _radius; }
	virtual const Vecteur2D calculateGravityVecteur2D() const { return _center; }
	virtual const double calculateWindowSize(Vecteur2D centerWindow) const { return (_center.distance(centerWindow) + _radius) * 2; }
	//virtual Form* clone() const;

	virtual Form* translate(Vecteur2D vec) { return new Circle(_center + vec, _radius, _color); }
	virtual Form* rotate(double degrees, Vecteur2D center = Vecteur2D(0, 0));
	virtual Form* homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0)) { return new Circle((_center * zoom) - center, _radius *= zoom, _color); }

	virtual Form* clone() const { return new Circle(*this); }

	//virtual const string serialize() const { return _center.serialize() + "," + to_string(_radius); }
	virtual void draw(Visitor* visitor);

	virtual ostream& display(ostream& o) const;
};

