#include "PolygonConvex.h"
#include "PolygonRegular.h"
#include "Triangle.h"
#include "VDrawByJavaFX.h"
#include "VReadByTxt.h"
#include "InitializeSocket.h"
#include "VSaveByTxt.h"
#include <Windows.h>

int main() {
	try {
		//Creation des formes
		Vector2D A(0, 0), B(-50, 100), C(75, -73), D(-40, 95), E(-140, 80), F(-120, 60), G(-100, -40), H(-80, 0), I(-60, 0);
		Circle* cercleA = new Circle(A, 50);
		Segment* segmentA = new Segment(B, C, Color(Color::RED));
		Triangle* triangleA = new Triangle(E, D, F);
		vector<Vector2D> vectors; vectors.push_back(E); vectors.push_back(F); vectors.push_back(G); vectors.push_back(H); vectors.push_back(I);
		PolygonConvex* polygonConvex = new PolygonConvex(vectors);
		PolygonRegular* polygonRegular = new PolygonRegular(Vector2D(120, 120), 60, 7);

		GroupForm* subRootA = new GroupForm();
		subRootA->insertChild(cercleA);
		subRootA->insertChild(triangleA);

		GroupForm* subRootB = new GroupForm(Color("1aEaBa"));
		subRootB->insertChild(segmentA);
		subRootB->insertChild(polygonRegular);

		GroupForm* rootForm = new GroupForm(Color("#CE0DC0"));
		rootForm->insertChild(subRootA);
		rootForm->insertChild(subRootB);
		rootForm->insertChild(polygonConvex);

		//On affiche toutes les formes du root
		cout << *rootForm << endl;

		//On se connecte au serveur
		VDrawByJavaFX* visitorJavaFX = new VDrawByJavaFX(true);
		rootForm->draw(visitorJavaFX, rootForm->getColor());
		
		cout << "TRANSLATE..." << endl;
		Sleep(3000);
		Vector2D translate(60, -40);
		rootForm->translate(translate);
		visitorJavaFX->clear();
		//visitorJavaFX->resize(rootForm->calculateWindowSize());
		rootForm->draw(visitorJavaFX, rootForm->getColor());


		Sleep(3000);
		rootForm->translate(-translate);
		visitorJavaFX->clear();
		//visitorJavaFX->resize(rootForm->calculateWindowSize());
		rootForm->draw(visitorJavaFX, rootForm->getColor());


		cout << "ROTATE..." << endl;
		Sleep(3000);
		Vector2D rotate = rootForm->calculateGravityVector2D();
		rootForm->rotate(180 * (Form::M_PI / 180), rotate);
		visitorJavaFX->clear();
		//visitorJavaFX->resize(rootForm->calculateWindowSize());
		rootForm->draw(visitorJavaFX, rootForm->getColor());

		Sleep(3000);
		rootForm->rotate(180 * (Form::M_PI / 180), rotate);
		visitorJavaFX->clear();
		//visitorJavaFX->resize(rootForm->calculateWindowSize());
		rootForm->draw(visitorJavaFX, rootForm->getColor());

		cout << "ZOOM..." << endl;
		Sleep(3000);
		Vector2D zoom = rootForm->calculateGravityVector2D();
		rootForm->homothety(2, zoom);
		visitorJavaFX->clear();
		//visitorJavaFX->resize(rootForm->calculateWindowSize());
		rootForm->draw(visitorJavaFX, rootForm->getColor());

		Sleep(3000);
		rootForm->homothety(0.5, zoom);
		visitorJavaFX->clear();
		//visitorJavaFX->resize(rootForm->calculateWindowSize());
		rootForm->draw(visitorJavaFX, rootForm->getColor());



		cout << "SPEED TRANSLATE + RESIZE" << endl;
		Sleep(3000);
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			visitorJavaFX->resize(rootForm->calculateWindowSize());
			rootForm->translate(Vector2D(3, 3));
			rootForm->draw(visitorJavaFX, rootForm->getColor());
		}
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			visitorJavaFX->resize(rootForm->calculateWindowSize());
			rootForm->translate(Vector2D(-3, -3));
			rootForm->draw(visitorJavaFX, rootForm->getColor());
		}

		cout << "SPEED ROTATE + RESIZE" << endl;
		Sleep(3000);
		for (int i = 0; i < 360; i++) {
			Sleep(5);
			visitorJavaFX->clear();
			visitorJavaFX->resize(rootForm->calculateWindowSize());
			rootForm->rotate(1 * (Form::M_PI / 180), rootForm->calculateGravityVector2D());
			rootForm->draw(visitorJavaFX, rootForm->getColor());
		}

		cout << "SPEED ZOOM + RESIZE" << endl;
		Sleep(3000);
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			visitorJavaFX->resize(rootForm->calculateWindowSize());
			rootForm->homothety(1.01, rootForm->calculateGravityVector2D());
			rootForm->draw(visitorJavaFX, rootForm->getColor());
		}
		for (int i = 0; i < 50; i++) {
			Sleep(50);
			visitorJavaFX->clear();
			visitorJavaFX->resize(rootForm->calculateWindowSize());
			rootForm->homothety(0.99, rootForm->calculateGravityVector2D());
			rootForm->draw(visitorJavaFX, rootForm->getColor());
		}

		getchar();
		visitorJavaFX->close();

		cout << "SAVE FORMS AND PRINT" << endl;
		Sleep(3000);
		VSaveByTxt* visitorSaveTxt = new VSaveByTxt();
		visitorSaveTxt->open("saveForms.txt");
		rootForm->save(visitorSaveTxt);
		visitorSaveTxt->close();
		cout << *rootForm << endl;


		cout << "READ FORMS AND PRINT" << endl;
		Sleep(3000);
		VReadByTxt* visitorReadTxt = new VReadByTxt();
		vector<Form*> forms = visitorReadTxt->read("saveForms.txt");

		for (unsigned int i = 0; i < forms.size(); i++) {
			cout << *forms[i] << endl;
		}


	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}