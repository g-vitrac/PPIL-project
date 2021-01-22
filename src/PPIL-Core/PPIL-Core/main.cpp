#include "Vecteur2D.h"
#include "Segment.h"
#include "Circle.h"
#include "GroupForm.h"
#include "World.h"

using namespace std;

int main() {
	Vecteur2D Vecteur2DA = Vecteur2D(0, 2, Form::BLUE);
	cout << Vecteur2DA << endl;
	Vecteur2D Vecteur2DB = Vecteur2D(4, 3, Form::GREEN);
	cout << Vecteur2DB << endl;
	Vecteur2D Vecteur2DC = Vecteur2D(4, 7, Form::BLUE);
	cout << Vecteur2DC << endl;
	Vecteur2D Vecteur2DD = Vecteur2D(0, 7, Form::GREEN);
	cout << Vecteur2DD << endl;

	Segment * segmentA = new Segment(Vecteur2DA, Vecteur2DB, Form::RED);
	//delete segmentA; fonctionne

	Circle * cercleA = new Circle(Vecteur2DC, 10.2, Form::RED);
	//delete cercleA; fonctionne
	Circle * cercleB = new Circle(Vecteur2DD, 3.5, Form::BLACK);
	//delete cercleB; fonctionne

	return 0;
	GroupForm* subRootA = new GroupForm(cercleA);
	GroupForm* subRootB = new GroupForm(cercleB);
	vector<Form*> vecteurForm;
	vecteurForm.push_back(subRootA);
	vecteurForm.push_back(subRootB);

	GroupForm* root = new GroupForm(vecteurForm);

	World world = World(root);
	cout << world << endl;

	//Problème liberation mémoire
	//delete root;
}