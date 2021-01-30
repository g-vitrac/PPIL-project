#include "Polygon.h"

Polygon::Polygon(int color) : Form(color)
{
}

Polygon::Polygon(vector<Vecteur2D> formVecteur2D, int color) : Form(color)
{
	if (formVecteur2D.size() > 2) {
		for (unsigned int i = 0; i < formVecteur2D.size(); i++) {
			_formVecteur2D.push_back(formVecteur2D[i]);
		}
	}
	else throw ("Polygon wrong");
}

Polygon::~Polygon()
{
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

ostream& Polygon::display(ostream& o) const
{
	o << "Polygon (";
	Form::display(o);
	return o << ")";
}
