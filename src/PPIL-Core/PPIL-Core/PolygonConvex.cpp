#include "PolygonConvex.h"

const double PolygonConvex::calculateArea() const
{
	double area = 0;
	Vector2D base = _formVecteur2D[0], last = _formVecteur2D[1] - base, next;
	for (size_t i = 1; i < _formVecteur2D.size() - 1; i++) {
		next = _formVecteur2D[i + 1] - base;
		area += abs(last.determinant(next)) / 2;
		last = next;
	}
	return area;
}
#include "VDraw.h"
void PolygonConvex::draw(const VDraw* visitor, const string& color) const
{
	visitor->draw(this, color);
}