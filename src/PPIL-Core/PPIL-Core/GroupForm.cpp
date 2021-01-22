#include "GroupForm.h"

GroupForm::GroupForm(vector<Form*> childsForm, Form* parentForm)
{
	for (unsigned int i = 0; i < childsForm.size(); i++) {
		_childsForm.push_back(childsForm[i]);
		_formVecteur2D.push_back(childsForm[i]->getGravityVecteur2D());
	}
	_parentForm = parentForm;
	calculateByChanging();
}

GroupForm::GroupForm(Form* childForm, Form* parentForm)
{
	_childsForm.push_back(childForm);
	_formVecteur2D.push_back(childForm->getGravityVecteur2D());
	_parentForm = parentForm;
	calculateByChanging();
}

GroupForm::~GroupForm()
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		delete _childsForm[i];
	}
	delete this;
}

const double GroupForm::calculateArea() const
{
	double sum = 0;
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		sum += _childsForm[i]->calculateArea();
	}
	return sum;
}

const double GroupForm::calculatePerimeter() const
{
	double sum = 0;
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		sum += _childsForm[i]->calculatePerimeter();
	}
	return sum;
}

void GroupForm::insertGroup(Form* form)
{
	_childsForm.push_back(form);
}

void GroupForm::insertGroup(GroupForm* form)
{
	_childsForm.push_back(form);
	form->_parentForm = this;
}

void GroupForm::removeGroup(Form* form)
{
	
}

void GroupForm::calculateByChanging()
{
	_area = calculateArea();
	_perimeter = calculatePerimeter();
	_gravityVecteur2D = calculateGravityVecteur2D();
}

ostream& GroupForm::display(ostream& o) const
{
	o << "GroupForm (";
	Form::display(o);
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		o << "\nForm " << i + 1 << " = ";
		_childsForm[i]->display(o);
	}
	return o << ")";
}
