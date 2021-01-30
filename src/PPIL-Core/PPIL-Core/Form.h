#pragma once
#include "Marking.h"
#include "Vecteur2D.h"
#include "Error.h"

#include <iostream>
#include <math.h> 
#include <vector>

using namespace std;

class Visitor;
class Form
{
protected:
	int _color = BLACK;
	vector<Vecteur2D> _formVecteur2D;
	
	//Marking* _anchorMarking;

public:	
	Form* _parentForm; //??????
	static const int BLACK = 0;
	static const int BLUE = 1;
	static const int RED = 2;
	static const int GREEN = 3;
	static const int YELLOW = 4;
	static const int CYAN = 5;

	Form();
	Form(int color); //From* parentForm : Comment dire au père de pointer sur this ? -> mettre les fils dans Form reglerai le soucis
	~Form();

	const int getColor() const;
	const int getSizeVecteur2D() const;
	Vecteur2D getVecteur2DByIndex(unsigned int index);
	/*
	const GroupForm* getParentForm() const;
	void setParentForm(GroupForm* parentForm);
	*/
	//Marking* getAnchorMarking() const;

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	Vecteur2D const calculateGravityVecteur2D() const;

	virtual void draw(Visitor* visitor) = 0;

	friend ostream& operator<<(ostream& o, const Form& F);
	virtual ostream& display(ostream& o) const;
};

