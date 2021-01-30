#pragma once
#include "Form.h"
#include "Vecteur2D.h"

class Segment : public Form
{
public:
	Segment(Vecteur2D Vecteur2DA, Vecteur2D Vecteur2DB, int color = BLACK);
	~Segment();

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;

	virtual void draw(Visitor* visitor);

	//virtual Form* clone() const;

	virtual ostream& display(ostream& o) const;
};

