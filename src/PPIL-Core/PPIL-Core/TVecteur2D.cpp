#include "Vecteur2D.h"

int main() {
	Vecteur2D A = Vecteur2D(5, 2);
	Vecteur2D B = Vecteur2D(4, 1);
	cout << "A = " << A << endl;
	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A + -B << endl;
		
	Vecteur2D u1, u2, u3, u4;
	u1 = A - B;
	u2 = 0.5 * A; //u2 = 0.5operator*(A) : echoue alors le compilateur cherche à faire : u2 = operator*(0.5, A)
	u3 = A * 0.5; //u3 = A.operator*(0.5)
	u4 = u1 + u2; //u4 = u1.operator+(u2)
	//A + B = u1; //Interdit par le compliateur grace au const gauche

	cout << "u1 = " << u1 << endl;
	cout << "u2 = " << u2 << endl;
	cout << "u3 = " << u3 << endl;
	cout << "u4 = " << u4 << endl;

	Vecteur2D v1(5, -3), v2(3, 5), v3, v4(-4, 3);
	v3 = -4 * v2;
	double a = v1 * v3; //a -> on obtient 0
	cout << "a = " << a << endl;
	double b = v4.norm();
	cout << "b = " << b << endl; //on doit trouver b = 


	return 0;
}