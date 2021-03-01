#include "Polygon.h"

Polygon::Polygon(vector<Vector2D> formVecteur2D, string color) : Form(color)
{
	if (formVecteur2D.size() > 2) {
		for (unsigned int i = 0; i < formVecteur2D.size(); i++) {
			_formVecteur2D.push_back(formVecteur2D[i]);
		}
	}
	else throw ("Polygon : polygon wrong");
}

const double Polygon::calculatePerimeter() const
{
	double perimeter = 0;
	unsigned int i;
	for (i = 0; i < _formVecteur2D.size() - 1; i++) {
		perimeter += _formVecteur2D[i].distance(_formVecteur2D[i + 1]);
	}
	perimeter += _formVecteur2D[i].distance(_formVecteur2D[0]);
	return perimeter;
}

Vector2D const Polygon::calculateGravityVector2D() const
{
	size_t size = _formVecteur2D.size();
	if (size > 0) {
		Vector2D r(0, 0);
		for (int i = 0; i < size; i++) {
			r = r + _formVecteur2D[i];
		}
		return r / (double)size;
	}
	else {
		throw Error("calculateGravityVector2D : collection size <= 0");
	}
}

Form* Polygon::translate(Vector2D vec)
{
	vector<Vector2D> formReturn;
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		formReturn.push_back(_formVecteur2D[i] + vec);
	}
	return NULL; //Juste infame...
	//return new Polygon(formReturn, _color);
}

Form* Polygon::homothety(double zoom, Vector2D center)
{
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] = (_formVecteur2D[i] * zoom) - center;
	}
	return NULL; //Juste infame...
}

Polygon::operator string() const
{
	ostringstream o; o << "Polygon (" << Form::operator string();
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		o << "\n         vector " << i + 1 << " = " << _formVecteur2D[i] << "\n";
	}
	o << ")";
	return o.str();
}
