#include "PolygonConvex.h"
#include "Visitor.h"

PolygonConvex::PolygonConvex(int color) : Polygon(color)
{
}

PolygonConvex::PolygonConvex(vector<Vecteur2D> formVecteur2D, int color) : Polygon(formVecteur2D, color)
{
}

PolygonConvex::~PolygonConvex()
{
}

const double PolygonConvex::calculateArea() const
{
	double area = 0;
	Vecteur2D base = _formVecteur2D[0], last = _formVecteur2D[1] - base, next;
	for (unsigned int i = 1; i < _formVecteur2D.size() - 1; i++) {
		next = _formVecteur2D[i + 1] - base;
		area += abs(last.determinant(next)) / 2;
		last = next;
	}
	return area;
}

void PolygonConvex::draw(Visitor* visitor)
{
	visitor->draw(this);
}

ostream& PolygonConvex::display(ostream& o) const
{
	o << "PolygonConvex (";
	Polygon::display(o);
	return o << ")";
}
