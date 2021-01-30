#include "Segment.h"
#include "Visitor.h"

Segment::Segment(Vecteur2D Vecteur2DA, Vecteur2D Vecteur2DB, int color) : Form(color)
{
    _formVecteur2D.push_back(Vecteur2DA);
    _formVecteur2D.push_back(Vecteur2DB);
}

Segment::~Segment()
{
}

double const Segment::calculateArea() const
{
    return 0;
}

double const Segment::calculatePerimeter() const
{
    return 0;
}

void Segment::draw(Visitor* visitor)
{
    visitor->draw(this);
}

/*
Form* Segment::clone() const
{
    Segment * segment = new Segment(*this);
    //Comment appeler le clone des Vecteur2Ds automatiquement ?
    segment->_Vecteur2DA = (Vecteur2D*)this->_Vecteur2DA->clone();
    segment->_Vecteur2DB = (Vecteur2D*)this->_Vecteur2DB->clone();
    return segment;
}
*/

ostream& Segment::display(ostream& o) const
{
    o << "Segment (";
    Form::display(o);
    return o << ")";
}
