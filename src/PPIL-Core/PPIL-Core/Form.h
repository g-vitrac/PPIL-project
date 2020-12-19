#pragma once
#include <iostream>

using namespace std;

class Form
{
protected:
	double _area = 0;
	double _perimeter = 0;
	int _color = BLACK;

public:
	static const int BLACK = 0;
	static const int BLUE = 1;
	static const int RED = 2;
	static const int GREEN = 3;
	static const int YELLOW = 4;
	static const int CYAN = 5;

	//Pourquoi Form(int color) fonctionne pas ?
	//Form(int color);

	const double getArea();
	const double getPerimeter();
	const int getColor();

	virtual double const calculateArea() const = 0;
	virtual double const calculatePerimeter() const = 0;
	virtual Form* clone() const = 0;

	friend ostream& operator<<(ostream & o, const Form & c);
	virtual ostream& afficher(ostream & o) const;
};

