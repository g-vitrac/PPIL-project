#include "Form.h"

const int Form::getColor() const
{
    return _color;
}

const double Form::getArea() const
{
    return _area;
}

const double Form::getPerimeter() const
{
    return _perimeter;
}

/*
Marking* Form::getAnchorMarking() const
{
    return _anchorMarking;
}
*/

Vecteur2D Form::getGravityVecteur2D() const
{
    return _gravityVecteur2D;
}

Vecteur2D Form::getVecteur2DByIndex(unsigned int index)
{
    if (_formVecteur2D.size() < index - 1)
        return _formVecteur2D[index];
    else throw Error("dépassement de tableau");
}

Vecteur2D Form::calculateGravityVecteur2D()
{
    int size = _formVecteur2D.size();
    if (size > 0) {
        double posX = 0;
        double posY = 0;
        for (int i = 0; i < size; i++) {
            posX += _formVecteur2D[i].getPosX();
            posY += _formVecteur2D[i].getPosY();
        }
        return Vecteur2D(posX / size, posY / size, _color);
    }
    else {
        throw Error("calculateGravityVecteur2D : collection taille <= 0");
    }
}

ostream& operator<<(ostream& o, const Form& f)
{
    return f.display(o);
}

ostream& Form::display(ostream& o) const
{
    o << "Form (";
    o << "\n     color = " << _color << ", area = " << _area << ", perimeter = " << _perimeter <<  ", gravity Vecteur2D = " << _gravityVecteur2D;
    for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
        o << "\n         - " << _formVecteur2D[i];
    }
    return o << ")";
}
