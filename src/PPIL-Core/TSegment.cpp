#pragma once

#include "Segment.h"
#include "Vecteur2D.h"

int main() {
	Vecteur2D A = Vecteur2D(0, 2);
	Vecteur2D B = Vecteur2D(4, 46);

	Segment* seg = new Segment(A, B, Form::RED);
	cout << *seg << endl;
}