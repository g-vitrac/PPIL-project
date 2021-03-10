#pragma once
#include "PolygonConvex.h"

class Triangle : public PolygonConvex
{
public:
	Triangle(Vector2D vecA, Vector2D vecB, Vector2D vecC, const Color& color = Color()) : PolygonConvex(color) { _formVecteur2D.push_back(vecA); _formVecteur2D.push_back(vecB); _formVecteur2D.push_back(vecC); }
	Triangle(vector<Vector2D> formVector2D, const Color&color = Color()) : PolygonConvex(formVector2D, color) {if (formVector2D.size() != 3) throw Error("Triangle : triangle size wrong");}

	virtual Form* clone() const { return new Triangle(*this); }

	virtual void save(VSave* visitor) const;

	virtual operator string() const { ostringstream o; o << "Triangle (" << PolygonConvex::operator string() << ")"; return o.str(); }
};

