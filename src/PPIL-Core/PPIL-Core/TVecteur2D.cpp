#include "Vector2D.h"

int main() {
	Vector2D A = Vector2D(5, 2);
	Vector2D B = Vector2D(4, 1);
	cout << "A = " << A << endl;
	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A + -B << endl;
		
	Vector2D u1, u2, u3, u4;
	u1 = A - B;
	u2 = 0.5 * A; //u2 = 0.5operator*(A) : echoue alors le compilateur cherche à faire : u2 = operator*(0.5, A)
	u3 = A * 0.5; //u3 = A.operator*(0.5)
	u4 = u1 + u2; //u4 = u1.operator+(u2)
	//A + B = u1; //Interdit par le compliateur grace au const gauche

	cout << "u1 = " << u1 << endl;
	cout << "u2 = " << u2 << endl;
	cout << "u3 = " << u3 << endl;
	cout << "u4 = " << u4 << endl;

	Vector2D v1(5, -3), v2(3, 5), v3, v4(-4, 3);
	v3 = -4 * v2;
	double a = v1 * v3; //a -> on obtient 0
	cout << "a = " << a << endl;
	double b = v4.norm();
	cout << "b = " << b << endl; //on doit trouver b = 
	{
		Vector2D v1(3,2), v2(7,4), v3, vtest;
		//v1 += 3;
		v3 = (v1 += v2);
		v1 += v2;
		v1 += v2;
		cout << v1 << endl;
		cout << v2 << endl;
		(v1 += v2) = v3;
		

		int a, b, c;
		a = 2;
		b = 5;
		a += b;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		c = a += b;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
		(a += b) = 3; //Absurde
		cout << a << endl;
	}
	{
		
		Vector2D v1(3, 2), v3;
		double a = 5;
		v1 *= a;
		cout << a << endl;
		cout << v1 << endl;
		//v3 = v1 *= a;
		cout << v1 << endl;
		cout << v3 << endl;
		cout << a << endl;
	}


	return 0;
}