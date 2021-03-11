#include "PolygonG.h"
#include "VDraw.h"

PolygonG::PolygonG(vector<Vector2D> formVecteur2D, const Color& color) : Form(color)
{
	if (formVecteur2D.size() > 2) {
		for (unsigned int i = 0; i < formVecteur2D.size(); i++) {
			_formVecteur2D.push_back(formVecteur2D[i]);
		}
	}
	else throw ("PolygonG : PolygonG size wrong");
}

const double PolygonG::calculatePerimeter() const
{
	double perimeter = 0;
	size_t i;
	for (i = 0; i < _formVecteur2D.size() - 1; i++) {
		perimeter += _formVecteur2D[i].distance(_formVecteur2D[i+1]);
	}
	perimeter += _formVecteur2D[i].distance(_formVecteur2D[0]);
	return perimeter;
}

Vector2D const PolygonG::calculateGravityVector2D() const
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

const Vector2D PolygonG::calculateWindowSize() const
{
	Vector2D max(0,0);
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		max = max.maximum(_formVecteur2D[i]);
	}
	return max * 2;
}

void PolygonG::translate(const Vector2D& vec)
{
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] += vec;
	}
}

void PolygonG::rotate(const double& radian, const Vector2D& center)
{
	Matrix22 matrix(radian);
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] = (matrix * (_formVecteur2D[i] - center)) + center;
	}
}

void PolygonG::homothety(const double& zoom, const Vector2D& center)
{
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		_formVecteur2D[i] = ((_formVecteur2D[i] - center) * zoom) + center;
	}
}

void PolygonG::draw(const VDraw* visitor, const string& color) const
{
	visitor->draw(this, color);
}

PolygonG::operator string() const
{
	ostringstream o; o << "PolygonG (" << Form::operator string();
	for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
		o << "\n         vector " << i + 1 << " = " << _formVecteur2D[i];
	}
	o << ")";
	return o.str();
}
