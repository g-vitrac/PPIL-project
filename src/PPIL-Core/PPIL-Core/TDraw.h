#pragma once

#include "VDrawByJavaFX.h"

#include <Windows.h>

class TDraw {
public:
	inline void test() {
		Vecteur2D A(0, 2), B(1, 9), C(9, 456);
		Circle* cercleA = new Circle(A, 10.2, Form::RED);
		Segment* segmentA = new Segment(B, C);
		try {
			VDrawByJavaFX* visitorJavaFX = new VDrawByJavaFX(true);

			cercleA->draw(visitorJavaFX);
			Sleep(2000);
			segmentA->draw(visitorJavaFX);

			visitorJavaFX->close();
		}
		catch (Error const& err) {
			cerr << err << endl;
		}
	}
};