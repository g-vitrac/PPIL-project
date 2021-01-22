#pragma once
#include "Marking.h"
#include "Vecteur2D.h"
#include "Error.h"

#include <iostream>
#include <math.h> 
#include <vector>

using namespace std;

class Form
{
protected:
	int _color;
	double _area;
	double _perimeter;
	vector<Vecteur2D> _formVecteur2D;
	//Marking* _anchorMarking;
	Vecteur2D _gravityVecteur2D;

public:	
	static const int BLACK = 0;
	static const int BLUE = 1;
	static const int RED = 2;
	static const int GREEN = 3;
	static const int YELLOW = 4;
	static const int CYAN = 5;

	const int getColor() const;
	const double getArea() const;
	const double getPerimeter() const;
	//Marking* getAnchorMarking() const;
	Vecteur2D getGravityVecteur2D() const;
	Vecteur2D getVecteur2DByIndex(unsigned int index);

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	Vecteur2D calculateGravityVecteur2D();

	friend ostream& operator<<(ostream& o, const Form& F);
	virtual ostream& display(ostream& o) const;
};

