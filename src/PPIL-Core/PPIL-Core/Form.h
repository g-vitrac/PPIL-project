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
	string _color = BLACK;
	Marking _anchorMarking;

public:
	Form* _parentForm; //??????
	const double M_PI = 3.14159265358979323846;
	static const string BLACK;
	static const string BLUE;
	static const string RED;
	static const string GREEN;
	static const string YELLOW;
	static const string CYAN;
	//static const string BLACK = string("#000000");

	explicit Form(string color = BLACK) : _color(color), _parentForm(NULL), _anchorMarking(Marking()) {}

	const string getColor() const { return _color; };
	/*
	const int getSizeVecteur2D() const { return _formVecteur2D.size(); }
	Vecteur2D getVecteur2DByIndex(unsigned int index) { if (_formVecteur2D.size() > index) return _formVecteur2D[index]; else throw Error("d�passement de tableau"); }
	*/

	//Marking* getAnchorMarking() const;

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	virtual const Vecteur2D calculateGravityVecteur2D() const = 0;

	virtual Form* translate(Vecteur2D vec) = 0;
	virtual Form* rotate(double degrees, Vecteur2D center = Vecteur2D(0, 0)) = 0;
	virtual Form* homothety(double zoom, Vecteur2D center = Vecteur2D(0,0)) = 0;

	virtual void draw(Visitor* visitor) = 0;

	virtual ostream& display(ostream& o) const;
	friend ostream& operator<<(ostream& o, const Form& f) { return f.display(o); }
};
