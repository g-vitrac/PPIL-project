#pragma once
#include "Vecteur2D.h"

class TVecteur2D {
public:

	inline void test() {
		Vecteur2D A = Vecteur2D(0, 2);
		Vecteur2D B = Vecteur2D(4, 1);
		cout << "A = " << A << endl;
		cout << "A + B = " << A + B << endl;
		cout << "A - B = " << A + -B << endl;
	}
};