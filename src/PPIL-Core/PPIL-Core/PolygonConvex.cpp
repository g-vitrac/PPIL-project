#include "PolygonConvex.h"
#include "VDraw.h"
#include "VSave.h"
#include "VRead.h"

const double PolygonConvex::calculateArea() const
{
	double area = 0;
	Vector2D base = _formVecteur2D[0], last = _formVecteur2D[1] - base, next;
	for (unsigned int i = 1; i < _formVecteur2D.size() - 1; i++) {
		next = _formVecteur2D[i + 1] - base;
		area += abs(last.determinant(next)) / 2;
		last = next;
	}
	return area;
}

void PolygonConvex::draw(VDraw* visitor)
{
	visitor->draw(this, this->getColor());
}