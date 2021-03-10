#pragma once

#include "VSaveByTxt.h"
#include <Windows.h>

int main() {
	try {
		VSaveByTxt* visitorDrawText = new VSaveByTxt();
		visitorDrawText->open(string("test.txt"));
		Vector2D A(0, 0), B(-100, 200), C(200, 200), D(-320, 200), E(-280, 160), F(-240, 120), G(-200, -80), H(-160, 0), I(-120, 0);
		Circle* cercleA = new Circle(A, 50);
		Circle* cercleB = new Circle(D, 30, Color(Color::BLACK));
		vector<Vector2D> forms; forms.push_back(E); forms.push_back(F); forms.push_back(G); forms.push_back(H); forms.push_back(I);
		PolygonConvex* polygonConv = new PolygonConvex(forms);
		Triangle* triangle = new Triangle(D, A, B, Color("aaaaaa"));
		Segment* segmentA = new Segment(B, C, Color(Color::YELLOW));
		GroupForm* subRootA = new GroupForm();
		GroupForm* subRootB = new GroupForm(Color(Color::BLUE));
		GroupForm* rootForm = new GroupForm();
		subRootA->insertChild(cercleA);
		subRootA->insertChild(triangle);
		subRootB->insertChild(segmentA);
		subRootB->insertChild(cercleB);
		rootForm->insertChild(subRootA);
		rootForm->insertChild(subRootB);
		rootForm->insertChild(polygonConv);

		rootForm->save(visitorDrawText);
		//visitorDrawText->clear();
		visitorDrawText->close();

		cout << *rootForm << endl;
	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}