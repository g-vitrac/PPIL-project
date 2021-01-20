#include "FormND.h"

const double FormND::getArea() const
{
    return _area;
}

const double FormND::getPerimeter() const
{
    return _perimeter;
}

/*
Marking* FormND::getAnchorMarking() const
{
    return _anchorMarking;
}
*/

Point FormND::getGravityPoint() const
{
    return _gravityPoint;
}

Point FormND::getPointToFormPoints(int index)
{
    if (_formPoints.size() < index - 1)
        return _formPoints[index];
    else throw Error("dépassement de tableau");
}

Point FormND::calculateGravityPoint()
{
    int size = _formPoints.size();
    if (size > 0) {
        double posX = 0;
        double posY = 0;
        for (int i = 0; i < size; i++) {
            posX += _formPoints[i].getPosX();
            posY += _formPoints[i].getPosY();
        }
        return Point(posX / size, posY / size, _color);
    }
    else {
        throw Error("calculateGravityPoint : collection taille <= 0");
    }
}

ostream& FormND::display(ostream& o) const
{
    o << "FormND (";
    Form::display(o);
    o << "\n     area = " << _area << ", perimeter = " << _perimeter <<  ", gravity point = " << _gravityPoint << ", form points = \n";
    for (unsigned int i = 0; i < _formPoints.size(); i++) {
        o << "          point " << i + 1 << " = " << _formPoints[i] << "\n";
    }
    return o << ")";
}
