#include "Vecteur2D.h"

Vecteur2D::Vecteur2D()
{
    _posX = 0;
    _posY = 0;
}

Vecteur2D::Vecteur2D(double posX, double posY)
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

const double Vecteur2D::getPosX() const
{
    return _posX;
}

const double Vecteur2D::getPosY() const
{
    return _posY;
}

const double Vecteur2D::distance(const Vecteur2D& v) const
{
    double posX = _posX - v._posX;
    double posY = _posY - v._posY;
    return sqrt((posX * posX) + (posY * posY));
}

const double Vecteur2D::determinant(const Vecteur2D& v) const
{
    return abs((_posX * v._posY) - (_posY * v._posX));
}

/*
Form* Vecteur2D::clone() const
{
    return new Vecteur2D(*this);
}
*/

Vecteur2D Vecteur2D::operator*(const double& d) 
{
    return Vecteur2D(_posX * d, _posY * d);
}

Vecteur2D Vecteur2D::operator+(const Vecteur2D& v) const
{
    return Vecteur2D(_posX + v._posX, _posY + v._posY);
}

Vecteur2D Vecteur2D::operator-() const
{
    return Vecteur2D(-_posX, -_posY);
}

Vecteur2D& Vecteur2D::operator=(const Vecteur2D& v)
{
    if (this != &v) {
        this->_posX = v._posX;
        this->_posY = v._posY;
    }
    return *this;
}

bool Vecteur2D::operator==(const Vecteur2D& v)
{
    return this->_posX == v._posX && this->_posY == v._posY;
}

ostream& operator<<(ostream& o, const Vecteur2D& v)
{
    o << "Vecteur2D (";
    return o << "position X = " << v.getPosX() << ", postion Y = " << v.getPosY() << ")";
}
