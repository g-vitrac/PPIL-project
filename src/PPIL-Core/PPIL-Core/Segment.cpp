#include "Segment.h"
#include "VDraw.h"
#include "VSave.h"
#include "VRead.h"

Form* Segment::rotate(double degrees, Vector2D center)
{
    double radiant = degrees * M_PI / 180;
    double vcos = cos(radiant);
    double vsin = sin(radiant);
    _vecA = _vecA - center;
    _vecB = _vecB - center;
    Vector2D A(_vecA.getPosX() * vcos - _vecA.getPosY() * vsin, _vecA.getPosX() * vsin + _vecA.getPosY() * vcos);
    Vector2D B(_vecB.getPosX() * vcos - _vecB.getPosY() * vsin, _vecB.getPosX() * vsin + _vecB.getPosY() * vcos);
    return new Segment(A + center, B + center, _color);
}

void Segment::draw(VDraw* visitor, const string& color) const
{
    visitor->draw(this, color);
}

void Segment::save(VSave* visitor) const
{
    visitor->save(this);
}