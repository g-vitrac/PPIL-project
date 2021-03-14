#include "Vecteur2D.h"
#include "Segment.h"
#include "PolygonConvex.h"
#include "GroupForm.h"

int main() {
	Vecteur2D A(2, 2), B(2, -2), C(-2, -2), D(-2, 2), tr(1, 3);
	Segment * S = new Segment(A, B);
	Segment* S2 = new Segment(C, D);

	GroupForm* subRootA = new GroupForm();
	GroupForm* subRootB = new GroupForm();
	subRootA->insertChild(S);
	subRootB->insertChild(S2);

	GroupForm* root = new GroupForm();
	root->insertChild(subRootA);
	root->insertChild(subRootB);
	cout << *root << endl;

	cout << "apres tr" << endl;
	Form* rootTr = root->translate(tr);
	cout << *rootTr << endl;
}