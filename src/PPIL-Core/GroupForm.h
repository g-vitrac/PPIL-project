#pragma once
#include "Form.h"

class GroupForm : public Form
{
private:
	vector<Form*> _childsForm;

public:
	GroupForm(vector<Form*> childsForm, Form* parentForm = NULL);
	GroupForm(Form* childForm, Form* parentForm = NULL);
	~GroupForm();

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	virtual const Vecteur2D calculateGravityVecteur2D() const;

	void insertGroup(Form* form);
	void removeGroup(Form* form);

	virtual void translate(Vecteur2D vec);
	virtual void homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0));

	virtual void draw(Visitor* visitor);

	virtual ostream& display(ostream& o) const;
};
