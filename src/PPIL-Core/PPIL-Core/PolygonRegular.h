#pragma once
#include "PolygonConvex.h"

/**
 * @brief Model of a regular polygon
*/
class PolygonRegular : public PolygonConvex
{
public:
	PolygonRegular(const Vector2D& centerVector2D, const double& radius, int numberSide, const Color& color = Color());
	PolygonRegular(vector<Vector2D> formVector2D, const Color& color = Color());

	virtual void save(VSave* visitor) const;

	virtual Form* clone() const { return new PolygonRegular(*this); }

	virtual operator string() const { ostringstream o; o << "PolygonRegular (" << PolygonConvex::operator string() << ")"; return o.str(); }
};

