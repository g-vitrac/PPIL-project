#include "Vecteur2D.h"

Vecteur2D::Vecteur2D()
{
    _posX = 0;
    _posY = 0;
}

Vecteur2D::Vecteur2D(double posX, double posY, int color)
{
    _posX = posX;
    _posY = posY;
}

Vecteur2D::Vecteur2D(const Vecteur2D& p)
{
    _posX = p._posX;
    _posY = p._posY;
}

Vecteur2D::~Vecteur2D()
{
}

double Vecteur2D::getPosX() const
{
    return _posX;
}

double Vecteur2D::getPosY() const
{
    return _posY;
}

/*
Form* Vecteur2D::clone() const
{
    return new Vecteur2D(*this);
}
*/

Vecteur2D& Vecteur2D::operator=(const Vecteur2D& p)
{
    if (this != &p) {
        this->_posX = p._posX;
        this->_posY = p._posY;
    }
    return *this;
}

bool Vecteur2D::operator==(const Vecteur2D& p)
{
    return this->_posX == p._posX && this->_posY == p._posY;
}


ostream& operator<<(ostream& o, const Vecteur2D& v)
{
    o << "Vecteur2D (";
    return o << "position X = " << v.getPosX() << ", postion Y = " << v.getPosY() << ")";
}
