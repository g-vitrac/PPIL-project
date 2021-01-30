#pragma once
#include <iostream>

using namespace std;

class Vecteur2D
{
private:
	double _posX;
	double _posY;

public:
	Vecteur2D();
	Vecteur2D(double posX, double posY);
	Vecteur2D(const Vecteur2D& p);
	~Vecteur2D();

	const double getPosX() const;
	const double getPosY() const;

	const double distance(const Vecteur2D& v) const;
	const double determinant(const Vecteur2D& v) const;
	//virtual Form* clone() const;

	Vecteur2D operator* (const double & d);
	Vecteur2D operator+ (const Vecteur2D& v) const;
	Vecteur2D operator- () const;
	Vecteur2D & operator= (const Vecteur2D& v);
	bool operator == (const Vecteur2D& v);
};
extern ostream& operator<<(ostream& o, const Vecteur2D& v);

