#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Vecteur2D
{
private:
	double _posX;
	double _posY;

public:
	explicit Vecteur2D(double posX = 0, double posY = 0) : _posX(posX), _posY(posY) {}

	const double getPosX() const { return _posX; }
	const double getPosY() const { return _posY; }

	const double operator* (const Vecteur2D& v) const { return _posX * v._posX + _posY * v._posY; }
	const Vecteur2D operator* (const double& d) const { return Vecteur2D(_posX * d, _posY * d); }
	const Vecteur2D operator+ (const Vecteur2D& v) const { return Vecteur2D(_posX + v._posX, _posY + v._posY); }
	const Vecteur2D operator- () const { return Vecteur2D(-_posX, -_posY); }
	const Vecteur2D operator- (const Vecteur2D& v) const { return *this + -v; }
	const Vecteur2D operator/ (const double& d) const { return Vecteur2D(_posX / d, _posY / d); }

	const double norm() const { return sqrt(*this * *this); }
	const double distance(const Vecteur2D& v) const { return (*this - v).norm(); }
	const double determinant(const Vecteur2D& v) const { return (_posX * v._posY) - (_posY * v._posX); }

	operator string() const { ostringstream o; o << "Vecteur2D(" << _posX << "," << _posY << ")"; return o.str(); }
};
inline const Vecteur2D operator* (const double& d, const Vecteur2D& v) { return v * d; }
inline ostream& operator<<(ostream& o, const Vecteur2D& v) { return o << (string)v; }

