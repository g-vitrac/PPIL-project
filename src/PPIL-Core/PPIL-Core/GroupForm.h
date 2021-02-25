#pragma once
#include "Form.h"

class GroupForm : public Form
{
private:
	vector<Form*> _childsForm;

public:
	GroupForm(string color = BLACK) : Form(color) {}
	~GroupForm();

	const int getChildsFormSize() const { return _childsForm.size(); }
	const Form* getChild(int index) const;

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	virtual const Vector2D calculateGravityVector2D() const;
	virtual const Vector2D calculateWindowSize() const;

	void insertChild(Form* form);
	void removeChild(int index);
	void replaceNode(Form* form);

	virtual Form* translate(Vector2D vec);
	virtual Form* rotate(double degrees, Vector2D center = Vector2D(0, 0));
	virtual Form* homothety(double zoom, Vector2D center = Vector2D(0, 0));

	virtual Form* clone() const;

	virtual void draw(Visitor* visitor, const string& color) const;

	virtual ostream& display(ostream& o) const;
};
