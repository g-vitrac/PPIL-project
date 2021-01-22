#pragma once
#include "Form.h"

class GroupForm : public Form
{
private:
	vector<Form*> _childsForm;
	Form* _parentForm;

public:
	GroupForm(vector<Form*> childsForm, Form* parentForm = NULL);
	GroupForm(Form* childForm, Form* parentForm = NULL);
	~GroupForm();

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;

	//Comment gerer insert et remove efficacement ?
	void insertGroup(Form* form);
	void insertGroup(GroupForm* form);
	void removeGroup(Form* form); //Cast en GroupForm ?

	void calculateByChanging();

	virtual ostream& display(ostream& o) const;
};
