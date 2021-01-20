#include "GroupForm.h"

GroupForm::GroupForm(vector<Form> childsForm, Form parentForm)
{
	for (unsigned int i = 0; i < childsForm.size(); i++) {
		_childsForm[i] = childsForm[i];
	}
	_parentForm = parentForm;
}

GroupForm::~GroupForm()
{
}
