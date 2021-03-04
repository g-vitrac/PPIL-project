#include "Polygon.h"
#include "VDraw.h"
#include "VSave.h"

Polygon::Polygon(vector<Vector2D> formVecteur2D, const Color& color) : Form(color)
{
	if (formVecteur2D.size() > 2) {
		for (unsigned int i = 0; i < formVecteur2D.size(); i++) {
			_formVecteur2D.push_back(formVecteur2D[i]);
		}
	}
	else throw ("Polygon : polygon wrong");
}

const Vector2D Polygon::getPoint(int index) const
{
	if (index < _formVecteur2D.size() && index >= 0) return _formVecteur2D[index];
	else throw Error("getForm : index overflow");
}

const double Polygon::calculatePerimeter() const
{
	double perimeter = 0;
	size_t i;
	for (i = 0; i < _formVecteur2D.size() - 1; i++) {
		perimeter += _formVecteur2D[i].distance(_formVecteur2D[i+1]);
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
			r += _formVecteur2D[i];
		}
		return r / (double)size;
	}
	else {
		throw Error("calculateGravityVector2D : collection size <= 0");
	}
}

void Polygon::translate(const Vector2D& vec)
{
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] += vec;
	}
}

void Polygon::rotate(const double& radian, const Vector2D& center)
{
	Matrix22 matrice = Matrix22(cos(radian), -sin(radian), sin(radian), cos(radian));
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] = (matrice * (_formVecteur2D[i] - center)) + center;
	}
}

void Polygon::homothety(const double& zoom, const Vector2D& center)
{
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] = ((_formVecteur2D[i] - center) * zoom) + center;
	}
}

/*
void Polygon::draw(const VDraw* visitor, const string& color) const
{
	visitor->draw(this, color);
}
*/

void Polygon::save(VSave* visitor) const
{
	visitor->save(this);
}

Polygon::operator string() const
{
	ostringstream o; o << "Polygon (" << Form::operator string();
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		o << "\n         vector " << i + 1 << " = " << _formVecteur2D[i];
	}
	o << ")";
	return o.str();
}
