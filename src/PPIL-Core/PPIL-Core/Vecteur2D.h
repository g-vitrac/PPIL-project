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
	Vecteur2D(double posX, double posY, int color);
	Vecteur2D(const Vecteur2D& p);
	~Vecteur2D();

	double getPosX() const;
	double getPosY() const;

	//virtual Form* clone() const;

	Vecteur2D& operator=(const Vecteur2D& p);
	bool operator == (const Vecteur2D& p);
};
extern ostream& operator<<(ostream& o, const Vecteur2D& v);

