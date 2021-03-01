#pragma once
#include "Vector2D.h"
#include "Error.h"

#include <iostream>
#include <sstream>
#include <string>
#include <math.h> 
#include <vector>
#include <regex>

using namespace std;

class VDraw;
class VSave;
class VRead;
class Form
{
protected:
	string _color;

public:
	Form* _parentForm; //??????
	static const double M_PI;
	static const string BLACK;
	static const string BLUE;
	static const string RED;
	static const string GREEN;
	static const string YELLOW;
	static const string CYAN;

	explicit Form(string color = BLACK) : _color(color), _parentForm(NULL) { if (!regex_match(color.c_str(), regex("^#?[0-9a-fA-F]{6}$"))) throw Error("Form : web color doesn't exist"); }

	const string getColor() const { return _color; };

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	virtual const Vector2D calculateGravityVector2D() const = 0;
	virtual const Vector2D calculateWindowSize() const = 0;

	virtual Form* translate(Vector2D vec) = 0;
	virtual Form* rotate(double degrees, Vector2D center = Vector2D(0,0)) = 0;
	virtual Form* homothety(double zoom, Vector2D center = Vector2D(0,0)) = 0;

	virtual Form* clone() const = 0;

	//virtual const string serialize(Vector2D origin) const = 0;
	virtual void draw(VDraw* visitor, const string& color) const = 0;
	virtual void save(VSave* visitor) const = 0;

	virtual operator string() const { ostringstream o; o << "Form (color = " << _color << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ", gravity = " << calculateGravityVector2D() << ")"; return o.str(); }
	friend ostream& operator<<(ostream& o, const Form& f) { return o << (string)f; }
};

