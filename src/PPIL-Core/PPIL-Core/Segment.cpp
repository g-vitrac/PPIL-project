#include "Segment.h"
#include "VDraw.h"
#include "VSave.h"
/*
Form* Segment::rotate(double degrees, Vector2D center)
{
    double radiant = degrees * M_PI / 180;
}
*/

void Segment::rotate(const double& radian, const Vector2D& center)
{
    Matrix22 matrice = Matrix22(cos(radian), -sin(radian), sin(radian), cos(radian));
    _vecA = (matrice * (_vecA - center)) + center;
    _vecB = (matrice * (_vecB - center)) + center;
}

void Segment::draw(const VDraw* visitor, const string& color) const
{
    visitor->draw(this, color);
}

void Segment::save(VSave* visitor) const
{
    visitor->save(this);
}