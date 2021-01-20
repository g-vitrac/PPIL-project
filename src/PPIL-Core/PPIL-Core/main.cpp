#include "Point.h"
#include "Segment.h"
#include "Circle.h"
#include "Square.h"
#include <vector>

using namespace std;

int main() {
	Point pointA = Point(0, 2, Form::BLUE);
	cout << pointA << endl;
	Point pointB = Point(4, 3, Form::GREEN);
	cout << pointB << endl;
	Point pointC = Point(4, 7, Form::BLUE);
	cout << pointA << endl;
	Point pointD = Point(0, 7, Form::GREEN);
	cout << pointB << endl;

	Segment segmentA = Segment(pointA, pointB, Form::RED);
	cout << segmentA << endl;

	Circle cercleA = Circle(pointC, 10.2, Form::RED);
	cout << cercleA << endl;


}