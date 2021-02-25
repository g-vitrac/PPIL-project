#pragma once

#include "VDrawByJavaFX.h"
#include <Windows.h>

int main() {
	try {
		VDrawByJavaFX* visitorJavaFX = new VDrawByJavaFX(true);
		Circle* cercleA = new Circle(Vector2D(50, 50), 100, "1aEaBa");
		visitorJavaFX->resize(cercleA->calculateWindowSize());
		cercleA->draw(visitorJavaFX, cercleA->getColor());
		/*
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

		Form* root = rootForm->clone();
		Circle* center = new Circle(root->calculateGravityVector2D(), 5, Form::BLACK);
	
		//TRANSLATION + GROUPE
		Sleep(2000);
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root = root->translate(Vector2D(3,3));
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root = root->translate(Vector2D(-3,-3));
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}

		//ZOOM + GROUPE
		Sleep(2000);
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root = root->homothety(1.01, root->calculateGravityVector2D());
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			root = root->homothety(0.99, root->calculateGravityVector2D());
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}

		//ROTATION + GROUPE
		Sleep(2000);
		for (int i = 0; i < 360; i++) {
			Sleep(5);
			visitorJavaFX->clear();
			root = root->rotate(1, root->calculateGravityVector2D());
			root->draw(visitorJavaFX, root->getColor());
			center->draw(visitorJavaFX, center->getColor());
		}
		*/
		visitorJavaFX->close();
	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}