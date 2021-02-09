#pragma once
#include "Marking.h"
#include "Vecteur2D.h"
#include "Error.h"

#include <iostream>
#include <sstream>
#include <string>
#include <math.h> 
#include <vector>

using namespace std;

class Visitor;
class Form
{
protected:
	int _color = BLACK;
	Marking _anchorMarking;

public:
	Form* _parentForm; //??????
	const double M_PI = 3.14159265358979323846;
	static const int BLACK = 0;
	static const int BLUE = 1;
	static const int RED = 2;
	static const int GREEN = 3;
	static const int YELLOW = 4;
	static const int CYAN = 5;

	explicit Form(int color = BLACK) : _color(color), _parentForm(NULL), _anchorMarking(Marking()) {}

	const int getColor() const { return _color; };
	/*
	const int getSizeVecteur2D() const { return _formVecteur2D.size(); }
	Vecteur2D getVecteur2DByIndex(unsigned int index) { if (_formVecteur2D.size() > index) return _formVecteur2D[index]; else throw Error("dépassement de tableau"); }
	*/

	//Marking* getAnchorMarking() const;

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	virtual const Vecteur2D calculateGravityVecteur2D() const = 0;

	virtual void translate(Vecteur2D vec) = 0;
	virtual void rotate(double degrees, Vecteur2D center = Vecteur2D(0, 0)) = 0;
	virtual void homothety(double zoom, Vecteur2D center = Vecteur2D(0,0)) = 0;

	virtual void draw(Visitor* visitor) = 0;

	virtual ostream& display(ostream& o) const;
	friend ostream& operator<<(ostream& o, const Form& f) { return f.display(o); }
};

