#pragma once
#include "FormND.h"

class GroupForm : public FormND
{
private:
	vector<Form> _childsForm;
	Form _parentForm;

public:
	GroupForm(vector<Form> childsForm, Form parentForm);
	~GroupForm();
};

