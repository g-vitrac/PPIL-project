#pragma once
#include "Form.h"
#include "Vecteur2D.h"

class Circle : public Form
{
private:
	Vecteur2D _center;
	double _radius;

public:
	explicit Circle(Vecteur2D center, double radius, int color = BLACK) : _center(center), _radius(radius), Form(color) {}

	const Vecteur2D getCenter() const { return _center; }
	const double getRadius() const { return _radius; }

	virtual const double calculateArea() const { return M_PI * _radius * _radius; }
	virtual const double calculatePerimeter() const { return 2 * M_PI * _radius; }
	virtual const Vecteur2D calculateGravityVecteur2D() const { return _center; }
	//virtual Form* clone() const;

	virtual void translate(Vecteur2D vec) { _center = _center + vec; }
	virtual void rotate(double degrees, Vecteur2D center = Vecteur2D(0, 0));
	virtual void homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0)) { _center = (_center * zoom) - center; _radius *= zoom; }

	virtual void draw(Visitor* visitor);

	virtual ostream& display(ostream& o) const;
};

