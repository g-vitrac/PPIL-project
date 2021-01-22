#include "Segment.h"

Segment::Segment(Vecteur2D Vecteur2DA, Vecteur2D Vecteur2DB, int color)
{
    _color = color;
    _formVecteur2D.push_back(Vecteur2DA);
    _formVecteur2D.push_back(Vecteur2DB);
    _gravityVecteur2D = calculateGravityVecteur2D();
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

/*
const bool Segment::isAdjacentSides(Segment* segment)
{
    return *this->_Vecteur2DA == *segment->_Vecteur2DA || *this->_Vecteur2DA == *segment->_Vecteur2DB || *this->_Vecteur2DB == *segment->_Vecteur2DA || *this->_Vecteur2DB == *segment->_Vecteur2DB;
}

const double Segment::calculateDistance()
{
    double posX = _Vecteur2DA->getPosX() - _Vecteur2DB->getPosX();
    double posY = _Vecteur2DA->getPosY() - _Vecteur2DB->getPosY();
    return sqrt((posX * posX) + (posY * posY));
}
*/

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
