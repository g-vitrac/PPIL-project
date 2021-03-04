#include "Circle.h"
#include "VDraw.h"
#include "VSave.h"

/*
Form* Circle::rotate(double degrees, Vector2D center)
{
	double radiant = degrees * M_PI / 180;
	double vcos = cos(radiant);
	double vsin = sin(radiant);
	_center = _center - center;
	Vector2D A(_center.getPosX() * vcos - _center.getPosY() * vsin, _center.getPosX() * vsin + _center.getPosY() * vcos);
	return new Circle(A + center, _radius, _color);
}
*/

void Circle::rotate(const double& radian, const Vector2D& center)
{
	Matrix22 matrice = Matrix22(cos(radian), -sin(radian), sin(radian), cos(radian));
	_center = (matrice * (_center - center)) + center;
}

void Circle::draw(const VDraw* visitor, const string& color) const
{
	visitor->draw(this, color);
}

void Circle::save(VSave* visitor) const
{
	visitor->save(this);
}
