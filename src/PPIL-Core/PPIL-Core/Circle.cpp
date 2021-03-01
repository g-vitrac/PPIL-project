#include "Circle.h"
#include "VDraw.h"
#include "VSave.h"
#include "VRead.h"

Form* Circle::rotate(double degrees, Vector2D center)
{
	double radiant = degrees * M_PI / 180;
	double vcos = cos(radiant);
	double vsin = sin(radiant);
	_center = _center - center;
	Vector2D A(_center.getPosX() * vcos - _center.getPosY() * vsin, _center.getPosX() * vsin + _center.getPosY() * vcos);
	return new Circle(A + center, _radius, _color);
}

void Circle::draw(VDraw* visitor, const string& color) const
{
	visitor->draw(this, color);
}

void Circle::save(VSave* visitor) const
{
	visitor->save(this);
}
