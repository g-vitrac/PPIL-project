#include "Polygon.h"
#include "Triangle.h"

int main() {
	Vector2D A(4, -3), B(7, -4), C(2, 3);
	vector<Vector2D> vectors; vectors.push_back(A); vectors.push_back(B); vectors.push_back(C);
	
	Polygon* triangle = new Triangle(vectors);

	cout << *triangle << endl;

	Vector2D centerTriangle(0, 0);
	triangle->homothety(2, centerTriangle);

	cout << *triangle << endl;
}