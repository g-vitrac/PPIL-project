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

	//Comment gerer insert et remove efficacement ?
	void insertGroup(Form* form);
	void removeGroup(Form* form);

	virtual ostream& display(ostream& o) const;
};
