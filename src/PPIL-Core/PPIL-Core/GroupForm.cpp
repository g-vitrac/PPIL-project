#include "GroupForm.h"
#include "VDraw.h"
#include "VSave.h"

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

const Vector2D GroupForm::calculateGravityVector2D() const
{
	size_t size = _childsForm.size();
	if (size > 0) {
		Vector2D r(0,0);
		for (int i = 0; i < size; i++) {
			r = r + _childsForm[i]->calculateGravityVector2D();
		}
		return r / (double)size;
	}
	throw Error("calculateGravityVector2D : childsForm empty");
}

const Vector2D GroupForm::calculateWindowSize() const
{
	Vector2D sizeMax = _childsForm[0]->calculateWindowSize();
	for (unsigned int i = 1; i < _childsForm.size(); i++) {
		sizeMax = sizeMax.maximum(_childsForm[i]->calculateWindowSize());
	}
	return sizeMax;
}

void GroupForm::translate(const Vector2D& vec)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->translate(vec);
	}
}

void GroupForm::rotate(const double& degrees, const Vector2D& center)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->rotate(degrees, center);
	}
}

void GroupForm::homothety(const double& zoom, const Vector2D& center)
{
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		_childsForm[i]->homothety(zoom, center);
	}
}

Form* GroupForm::clone() const
{
	GroupForm* groupForm = new GroupForm(_color);
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		groupForm->insertChild(_childsForm[i]->clone());
	}
	return groupForm;
}

void GroupForm::draw(const VDraw* visitor, const string& color) const
{
	visitor->draw(this, color);
}

void GroupForm::save(VSave* visitor) const
{
	visitor->save(this);
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

	size_t size = _childsForm.size();
	if (index < size && index >= 0) {
		delete _childsForm[index];
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

GroupForm::operator string() const
{
	ostringstream o; o << "GroupForm (" << Form::operator string();
	for (unsigned int i = 0; i < _childsForm.size(); i++) {
		o << "\n      child " << i + 1 << " = " << *_childsForm[i];
	}
	o << ")";
	return o.str();
}
