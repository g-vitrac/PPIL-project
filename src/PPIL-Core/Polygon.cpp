#include "Polygon.h"

Polygon::Polygon(vector<Vecteur2D> formVecteur2D, int color) : Form(color)
{
	if (formVecteur2D.size() > 2) {
		for (unsigned int i = 0; i < formVecteur2D.size(); i++) {
			_formVecteur2D.push_back(formVecteur2D[i]);
		}
	}
	else throw ("Polygon wrong");
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

Vecteur2D const Polygon::calculateGravityVecteur2D() const
{
	int size = _formVecteur2D.size();
	if (size > 0) {
		Vecteur2D r(0, 0);
		for (int i = 0; i < size; i++) {
			r = r + _formVecteur2D[i];
		}
		return r / size;
	}
	else {
		throw Error("calculateGravityVecteur2D : collection taille <= 0");
	}
}

void Polygon::translate(Vecteur2D vec)
{
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] = _formVecteur2D[i] + vec;
	}
}

void Polygon::homothety(double zoom, Vecteur2D center)
{
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] = (_formVecteur2D[i] * zoom) - center;
	}
}

ostream& Polygon::display(ostream& o) const
{
	o << "Polygon (";
	Form::display(o);
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		o << "\n         - " << _formVecteur2D[i];
	}
	return o << ")";
}
