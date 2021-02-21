#include "Vecteur2D.h"
#include "Segment.h"
#include "Circle.h"
#include "PolygonConvex.h"
#include "GroupForm.h"

int main() {
	Vecteur2D A(2, 2), B(2, -2), C(-2, -2), D(-2, 2), tr(1, 3);
	Vecteur2D E(-2,0), F(2, 0);
	vector<Vecteur2D> vec;
	vec.push_back(A); vec.push_back(B); vec.push_back(C); vec.push_back(D);
	Segment* S = new Segment(E, F);
	Circle* CA = new Circle(D, 30);
	cout << *S << endl;
	//CA->rotate(180, CA->calculateGravityVecteur2D());
	S->rotate(180, S->calculateGravityVecteur2D());
	cout << *S << endl;
	/*
	PolygonConvex* P = new PolygonConvex(vec);

	GroupForm* subRootA = new GroupForm(S);
	GroupForm* subRootB = new GroupForm(P);

	GroupForm* root = new GroupForm(subRootA);
	root->insertGroup(subRootB);
	cout << *root << endl;

	root->homothety(2, root->calculateGravityVecteur2D());
	cout << *root << endl;
	*/
}