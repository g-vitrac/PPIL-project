#pragma once
#include "Form.h"

class GroupForm : public Form
{
private:
	vector<Form*> _childsForm;

public:
	GroupForm() {}
	~GroupForm();

	const Form* getChild(int index) const;

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	virtual const Vecteur2D calculateGravityVecteur2D() const;
	virtual const double calculateWindowSize(Vecteur2D centerWindow) const;

	void insertChild(Form* form);
	void removeChild(int index);
	void replaceNode(Form* form);

	virtual Form* translate(Vecteur2D vec);
	virtual Form* rotate(double degrees, Vecteur2D center = Vecteur2D(0, 0));
	virtual Form* homothety(double zoom, Vecteur2D center = Vecteur2D(0, 0));

	virtual Form* clone() const;

	virtual void draw(Visitor* visitor);

	virtual ostream& display(ostream& o) const;
};
