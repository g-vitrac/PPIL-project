#pragma once

#include "PolygonConvex.h"
#include "PolygonRegular.h"
#include "VDrawByJavaFX.h"
#include "InitializeSocket.h"
#include <Windows.h>

int main() {
	try {
		VDrawByJavaFX* visitorJavaFX = new VDrawByJavaFX(true);
		Vector2D A(0, 0), B(-100, 200), C(200, 200), D(-320,200), E(-280,160), F(-240,120), G(-200,-80), H(-160,0), I(-120,0);
		Circle* cercleA = new Circle(A, 50);
		Circle* cercleB = new Circle(D, 30);
		Segment* segmentA = new Segment(B, C, Color(Color::RED));
		vector<Vector2D> forms; forms.push_back(E); forms.push_back(F); forms.push_back(G); forms.push_back(H); forms.push_back(I);
		PolygonConvex* polygonConvex = new PolygonConvex(forms);
		PolygonRegular* polygonRegular = new PolygonRegular(Vector2D(300, 120), 150, 5);
		GroupForm* subRootA = new GroupForm();
		GroupForm* subRootB = new GroupForm(Color("1aEaBa"));
		GroupForm* rootForm = new GroupForm(Color("#CE0DC0"));
		subRootA->insertChild(cercleA);
		subRootA->insertChild(polygonConvex);
		subRootB->insertChild(segmentA);
		subRootB->insertChild(cercleB);
		rootForm->insertChild(subRootA);
		rootForm->insertChild(subRootB);
		rootForm->insertChild(polygonRegular);

		Form* root = rootForm->clone();
		Circle* center = new Circle(root->calculateGravityVector2D(), 5);
	
		//TRANSLATION + GROUPE
		Sleep(2000);
		for (int i =0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root->translate(Vector2D(3,3));
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root->translate(Vector2D(-3,-3));
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}

		//ZOOM + GROUPE
		Sleep(2000);
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root->homothety(1.01, root->calculateGravityVector2D());
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root->homothety(0.99, root->calculateGravityVector2D());
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}

		//ROTATION + GROUPE
		Sleep(2000);
		for (int i = 0; i < 360; i++) {
			Sleep(5);
			visitorJavaFX->clear();
			root->rotate(1 * (Form::M_PI / 180), root->calculateGravityVector2D());
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}
		visitorJavaFX->close();
	}	
	catch (Error const& err) {
		cerr << err << endl;
	}
}