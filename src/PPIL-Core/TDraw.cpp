#pragma once

#include "VDrawByJavaFX.h"
#include <Windows.h>

int main() {
	Vecteur2D A(50, 50), B(1, 9), C(9, 456);
	Circle* cercleA = new Circle(A, 50, Form::RED);
	Segment* segmentA = new Segment(B, C);
	try {
		VDrawByJavaFX* visitorJavaFX = new VDrawByJavaFX(true);

		segmentA->draw(visitorJavaFX);
		cercleA->draw(visitorJavaFX);

		visitorJavaFX->close();
	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}