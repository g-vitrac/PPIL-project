#pragma once

#include "VSaveByTxt.h"
#include <Windows.h>

int main() {
	try {
		VSaveByTxt* visitorDrawText = new VSaveByTxt();
		visitorDrawText->open(string("test.txt"));
		Vector2D A(0, 0), B(-100, 200), C(200, 200), D(-70, -83);
		Circle* cercleA = new Circle(A, 50, "1aEaBa");
		Circle* cercleB = new Circle(D, 30, "1aEaBa");
		Segment* segmentA = new Segment(B, C, Form::YELLOW);
		GroupForm* subRootA = new GroupForm();
		GroupForm* subRootB = new GroupForm(Form::RED);
		GroupForm* rootForm = new GroupForm("#CE0DC0");
		subRootA->insertChild(cercleA);
		subRootB->insertChild(segmentA);
		subRootB->insertChild(cercleB);
		rootForm->insertChild(subRootA);
		rootForm->insertChild(subRootB);

		rootForm->save(visitorDrawText);
		subRootB->save(visitorDrawText);
		//visitorDrawText->clear();
		visitorDrawText->close();

		cout << *rootForm << endl;
	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}