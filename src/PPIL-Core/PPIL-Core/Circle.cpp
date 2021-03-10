#include "Circle.h"
#include "VDraw.h"
#include "VSave.h"

void Circle::rotate(const double& radian, const Vector2D& center)
{
	Matrix22 matrix(radian);
	_center = (matrix * (_center - center)) + center;
}

void Circle::draw(const VDraw* visitor, const string& color) const
{
	visitor->draw(this, color);
}

void Circle::save(VSave* visitor) const
{
	visitor->save(this);
}
