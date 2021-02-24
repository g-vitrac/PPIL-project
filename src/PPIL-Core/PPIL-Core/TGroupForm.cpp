#pragma once

#include "Vecteur2D.h"
#include "GroupForm.h"
#include "Circle.h"

int main() {
	try {
		Vecteur2D A(0, 2), B(3, 4), C(7, 2);

		Circle* cercleA = new Circle(A, 10.2, Form::RED);
		//delete cercleA; fonctionne
		Circle* cercleB = new Circle(B, 3.5, Form::BLACK);
		//delete cercleB; fonctionne
		Circle* cercleC = new Circle(C, 1.5, Form::BLACK);

		GroupForm* subRootA = new GroupForm();
		GroupForm* subRootB = new GroupForm();
		GroupForm* root = new GroupForm();

		subRootA->insertChild(cercleA);
		subRootA->insertChild(cercleB);
		subRootB->insertChild(cercleC);
		root->insertChild(subRootA);
		root->insertChild(subRootB);

		GroupForm* root2 = (GroupForm*)root->clone();
		((GroupForm*)root2->getChild(0))->removeChild(0);
		root2->insertChild(root2);
		cout << *root2 << endl;

		//subRootA->removeChild(0);
		//cout << *subRootA << endl;
		//cout << *subRootA2 << endl;

		exit(0);

		//cout << *subRootA1 << endl;
		//cout << *subRootA2 << endl;

		//GroupForm* subRootA3 = subRootA2->insertChild(cercleA);
		//GroupForm* subRootA4 = subRootA3->editNode(cercleC);

	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}