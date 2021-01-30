#include "Form.h"

Form::Form()
{
}

Form::Form(int color)
{
    _color = color;
}

Form::~Form()
{
}

const int Form::getColor() const
{
    return _color;
}

const int Form::getSizeVecteur2D() const
{
    return _formVecteur2D.size();
}

Vecteur2D Form::getVecteur2DByIndex(unsigned int index)
{
    if (_formVecteur2D.size() > index)
        return _formVecteur2D[index];
    else throw Error("dépassement de tableau");
}

/*
const GroupForm* Form::getParentForm() const
{
    return _parentForm;
}

void Form::setParentForm(GroupForm* parentForm)
{
    _parentForm = parentForm;
}
*/

/*
Marking* Form::getAnchorMarking() const
{
    return _anchorMarking;
}
*/

const Vecteur2D Form::calculateGravityVecteur2D() const
{
    int size = _formVecteur2D.size();
    if (size > 0) {
        double posX = 0;
        double posY = 0;
        for (int i = 0; i < size; i++) {
            posX += _formVecteur2D[i].getPosX();
            posY += _formVecteur2D[i].getPosY();
        }
        return Vecteur2D(posX / size, posY / size);
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
    o << "\n     color = " << _color << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() <<  ", gravity Vecteur2D = " << calculateGravityVecteur2D();
    for (unsigned int i = 0; i < _formVecteur2D.size(); i++) {
        o << "\n         - " << _formVecteur2D[i];
    }
    return o << ")";
}
