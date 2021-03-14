#include "Circle.h"
#include "Segment.h"

int main() {
	Vector2D A(4, -3), B(7,-4), U(2, 3);
	Segment AB(A, B);

	cout << AB << endl;

	Form* form = AB.translateClone(U);
	cout << U << endl;
	cout << AB << endl;
	cout << *form << endl;

	AB.translate(U);
	cout << U << endl;
	cout << AB << endl;
	
	return 0;
 }