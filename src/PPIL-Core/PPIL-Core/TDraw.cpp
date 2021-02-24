#pragma once

#include "VDrawByJavaFX.h"
#include <Windows.h>

int main() {
	Vecteur2D A(40, 140), B(-200, 0), C(200, 0);
	Circle* cercleA = new Circle(A, 200, Form::RED);
	Segment* segmentA = new Segment(B, C);
	try {

		VDrawByJavaFX* visitorJavaFX = new VDrawByJavaFX(true);
		visitorJavaFX->resize(cercleA);
		cercleA->draw(visitorJavaFX);
	
		//visitorJavaFX->resize(segmentA);
		//segmentA->draw(visitorJavaFX);
		visitorJavaFX->close();
		/*
		Sleep(2000);
		visitorJavaFX->clear();
		Sleep(2000);
		visitorJavaFX->resize(segmentA);
		segmentA->draw(visitorJavaFX);
		Sleep(2000);
		Segment* segmentB = (Segment*)segmentA->translate(C);
		segmentB->draw(visitorJavaFX);
		Sleep(2000);
		visitorJavaFX->close();
		*/
		/*
		cercleA->draw(visitorJavaFX);

		visitorJavaFX->close();
		*/
	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}