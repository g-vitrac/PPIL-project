#include "GroupForm.h"
#include "Visitor.h"

GroupForm::GroupForm(vector<Form*> childsForm, Form* parentForm)
{
	for (unsigned int i = 0; i < childsForm.size(); i++) {
		insertGroup(childsForm[i]);
	}
}

GroupForm::GroupForm(Form* childForm, Form* parentForm)
{
	insertGroup(childForm);
}

GroupForm::~GroupForm()
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		delete _childsForm[i];
	}
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

const Vecteur2D GroupForm::calculateGravityVecteur2D() const
{
	int size = _childsForm.size();
	Vecteur2D r(0, 0);
	for (int i = 0; i < size; i++) {
		r = r + _childsForm[i]->calculateGravityVecteur2D();
	}
	return r / size;
}

Form* GroupForm::translate(Vecteur2D vec)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->translate(vec);
	}
	return NULL;
}

Form* GroupForm::homothety(double zoom, Vecteur2D center)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->homothety(zoom, center);
	}
	return NULL;
}

void GroupForm::draw(Visitor* visitor)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->draw(visitor);
	}
}

void GroupForm::insertGroup(Form* form)
{
	this->_childsForm.push_back(form);
	form->_parentForm = this;
}

void GroupForm::removeGroup(Form* form)
{
	Form* save = form->_parentForm;
	form->_parentForm = NULL;
	bool isErase = false;
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		if (_childsForm[i]->_parentForm == NULL) {
			_childsForm.erase(_childsForm.begin() + i);
			isErase = true;
			break;
		}
	}
	if (!isErase) form->_parentForm = save;
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
