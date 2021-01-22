#pragma once
#include "Form.h"
#include "Vecteur2D.h"

class Segment : public Form
{
public:
	Segment(Vecteur2D Vecteur2DA, Vecteur2D Vecteur2DB, int color);
	~Segment();

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	//const bool isAdjacentSides(Segment* segment);
	//const double calculateDistance();

	//virtual Form* clone() const;

	virtual ostream& display(ostream& o) const;
};

