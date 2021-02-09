#include "Form.h"

ostream& Form::display(ostream& o) const
{
    o << "Form (";
    o << "\n     color = " << _color << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ", gravity Vecteur2D = " << calculateGravityVecteur2D();
    return o << ")";
}