#include "Form.h"

const double Form::M_PI = 3.141592;
const string Form::BLACK = "#000000";
const string Form::BLUE = "#0800FE";
const string Form::RED = "#FE0001";
const string Form::GREEN = "#0C9026";
const string Form::YELLOW = "#BFED00";
const string Form::CYAN = "#22FDF5";

ostream& Form::display(ostream& o) const
{
    o << "Form (";
    o << "\n     color = " << _color << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ", gravity Vector2D = " << calculateGravityVector2D();
    return o << ")";
}