#include "GroupForm.h"
#include "Visitor.h"

GroupForm::~GroupForm()
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		delete _childsForm[i];
	}
	this->_parentForm = NULL;
}

const Form* GroupForm::getChild(int index) const
{
	if (index < _childsForm.size() && index >= 0) return _childsForm[index];
	else throw Error("getChild : index overflow");
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
	if (size > 0) {
		Vecteur2D r(0, 0);
		for (int i = 0; i < size; i++) {
			r = r + _childsForm[i]->calculateGravityVecteur2D();
		}
		return r / size;
	}
	throw Error("calculateGravityVecteur2D : childsForm empty");
}

const double GroupForm::calculateWindowSize(Vecteur2D centerWindow) const
{
	return 0.0;
}

Form* GroupForm::translate(Vecteur2D vec)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->translate(vec);
	}
	return NULL;
}

Form* GroupForm::rotate(double degrees, Vecteur2D center)
{
	return nullptr;
}

Form* GroupForm::homothety(double zoom, Vecteur2D center)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->homothety(zoom, center);
	}
	return NULL;
}

Form* GroupForm::clone() const
{
	GroupForm* groupForm = new GroupForm();
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		groupForm->insertChild(_childsForm[i]->clone());
	}
	return groupForm;
}

void GroupForm::draw(Visitor* visitor)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->draw(visitor);
	}
}

void GroupForm::insertChild(Form* form)
{
	Form* clone = form->clone();
	_childsForm.push_back(clone);
	clone->_parentForm = this;
}

void GroupForm::removeChild(int index)
{
	/*
	int size = _childsForm.size();
	if (index < size && index >= 0) {
		delete (_childsForm[index]);
		_childsForm.erase(_childsForm.begin() + index);
		return NULL;
	}
	throw Error("removeChild : index overflow");
	*/

	int size = _childsForm.size();
	if (index < size && index >= 0) {
		delete (_childsForm[index]);
		_childsForm.erase(_childsForm.begin() + index);
	}
	else throw Error("removeChild : index overflow");

	/*
	GroupForm* groupForm = (GroupForm*)this->clone();
	Form* save = form->_parentForm;
	form->_parentForm = NULL;
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		if (_childsForm[i]->_parentForm == NULL) {
			delete groupForm->_childsForm[i];
			groupForm->_childsForm.erase(groupForm->_childsForm.begin() + i);
			break;
		}
	}
	form->_parentForm = save;
	return groupForm;
	*/
}

void GroupForm::replaceNode(Form* form)
{
	/*
	Form* clone = form->clone();
	Form* save 
	if (_parentForm != NULL) {
		GroupForm* parent = (GroupForm*)_parentForm;
		_parentForm = NULL;
		for (unsigned int i = 0; i < parent->_childsForm.size() && _childsForm[i]->_parentForm != NULL; i++);
		clone->_parentForm = parent;
	}
	delete _childsForm[i];
	_childsForm[i] = clone;
	*/
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
