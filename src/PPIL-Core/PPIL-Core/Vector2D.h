#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Vector2D
{
private:
	double _posX;
	double _posY;

public:
	explicit Vector2D() : _posX(0), _posY(0) {}
	explicit Vector2D(double pos) : _posX(pos), _posY(pos) {}
	explicit Vector2D(double posX, double posY) : _posX(posX), _posY(posY) {}

	const double getPosX() const { return _posX; }
	const double getPosY() const { return _posY; }

	const double operator* (const Vector2D& v) const { return _posX * v._posX + _posY * v._posY; }
	const Vector2D operator* (const double& d) const { return Vector2D(_posX * d, _posY * d); }
	const Vector2D operator+ (const Vector2D& v) const { return Vector2D(_posX + v._posX, _posY + v._posY); }
	const Vector2D operator+ (const double& d) const { return Vector2D(_posX + d, _posY + d); }
	const Vector2D operator- () const { return Vector2D(-_posX, -_posY); }
	const Vector2D operator- (const Vector2D& v) const { return *this + -v; }
	const Vector2D operator/ (const double& d) const { return Vector2D(_posX / d, _posY / d); }
	//const string operator+ (const string& s) const { return to_string(_posX) + "," + to_string(_posY); }

	const double norm() const { return sqrt(*this * *this); }
	const double distance(const Vector2D& v) const { return (*this - v).norm(); }
	const double determinant(const Vector2D& v) const { return (_posX * v._posY) - (_posY * v._posX); }
	const Vector2D maximum(const Vector2D& v) const { return Vector2D(max(abs(_posX), abs(v._posX)), max(abs(_posY), abs(v._posY))); }

	const string serialize() const { return to_string(_posX) + "," + to_string(_posY); }

	operator string() const { ostringstream o; o << "Vector2D(" << _posX << "," << _posY << ")"; return o.str(); }
};
inline const Vector2D operator* (const double& d, const Vector2D& v) { return v * d; }
inline const Vector2D operator+ (const double& d, const Vector2D& v) { return v + d; }
//inline const string operator+ (const string& s, const Vector2D& v) { return v; }
inline ostream& operator<<(ostream& o, const Vector2D& v) { return o << (string)v; }

