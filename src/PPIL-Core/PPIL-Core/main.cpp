#include "Vecteur2D.h"
#include "Segment.h"
#include "Circle.h"
#include "GroupForm.h"
#include "World.h"
#include "PolygonConvex.h"

#include "TCircle.h"
#include "TSegment.h"
#include "TVecteur2D.h"
#include "TPolygonConvex.h"
#include "TDraw.h"
#include "TGroupForm.h"

using namespace std;

int main() {

	//TCircle tcircle = TCircle(); tcircle.test();
	//TSegment tsegment = TSegment(); tsegment.test();
	//TVecteur2D tvecteur2D = TVecteur2D(); tvecteur2D.test();
	//TPolygonConvex tpolygonConvex = TPolygonConvex(); tpolygonConvex.test();
	TDraw draw = TDraw(); draw.test();
	//TGroupForm groupForm = TGroupForm(); groupForm.test();

	/*
	Vecteur2D Vecteur2DA = Vecteur2D(0, 2);
	cout << Vecteur2DA << endl;
	Vecteur2D Vecteur2DB = Vecteur2D(4, 3);
	cout << Vecteur2DB << endl;
	Vecteur2D Vecteur2DC = Vecteur2D(4, 7);
	cout << Vecteur2DC << endl;
	Vecteur2D Vecteur2DD = Vecteur2D(0, 7);
	cout << Vecteur2DD << endl;

	Segment * segmentA = new Segment(Vecteur2DA, Vecteur2DB, Form::RED);
	//delete segmentA; fonctionne
	*/
}