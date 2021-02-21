#pragma once

#include "Vecteur2D.h"
#include "GroupForm.h"
#include "Circle.h"

int main() {
	Vecteur2D A(0, 2), B(3, 4), C(7, 2);

	Circle* cercleA = new Circle(A, 10.2, Form::RED);
	//delete cercleA; fonctionne
	Circle* cercleB = new Circle(B, 3.5, Form::BLACK);
	//delete cercleB; fonctionne
	Circle* cercleC = new Circle(C, 1.5, Form::BLACK);

	GroupForm* subRootA = new GroupForm(cercleA);
	GroupForm* subRootB = new GroupForm(cercleB);
	GroupForm* subRootC = new GroupForm(cercleC);

	vector<Form*> vecteurForm;
	vecteurForm.push_back(subRootA);
	vecteurForm.push_back(subRootB);

	GroupForm* root = new GroupForm(vecteurForm);
	root->insertGroup(subRootB);
	cout << *root << endl;

	root->removeGroup(subRootA);
	root->removeGroup(subRootB);
	cout << *root << endl;
}