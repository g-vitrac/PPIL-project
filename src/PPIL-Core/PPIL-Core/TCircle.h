#pragma once

#include "Circle.h"
#include "Vecteur2D.h"

class TCircle {
public:

	inline void test() {
		Vecteur2D A = Vecteur2D(0, 2);

		Circle* cercleA = new Circle(A, 10.2, Form::RED);
		cout << *cercleA << endl;
	}
};