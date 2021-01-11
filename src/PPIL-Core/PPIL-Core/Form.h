#pragma once
#include "Error.h"
#include <iostream>
#include <math.h> 

using namespace std;

class Form
{
protected:
	int _color;

public:
	static const int BLACK = 0;
	static const int BLUE = 1;
	static const int RED = 2;
	static const int GREEN = 3;
	static const int YELLOW = 4;
	static const int CYAN = 5;

	const int getColor() const;

	//Pourquoi Form(int color) fonctionne pas ?
	//Form(int color);
	
	friend ostream& operator<<(ostream & o, const Form & c);
	virtual ostream& display(ostream & o) const;
};

