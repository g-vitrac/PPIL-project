#include "Point.h"
#include "Segment.h"
#include "Circle.h"

using namespace std;

int main() {
	Point* pointA = new Point(Form::BLUE, 3, 5);
	//cout << *pointA << endl;
	Point* pointB = new Point(Form::GREEN, 6, 2);
	//cout << *pointB << endl;
	Point* pointC = new Point(Form::BLUE, 4, 13);
	//cout << *pointA << endl;
	Point* pointD = new Point(Form::GREEN, 9, 4);
	//cout << *pointB << endl;

	Segment* segmentA = new Segment(Form::CYAN, pointA, pointB);
	//cout << *segmentA << endl;

	Segment* segmentB = new Segment(Form::CYAN, pointC, pointD);
	//cout << *segmentB << endl;

	Circle* circle = new Circle(Form::RED, pointC, 3);
	//cout << *circle << endl;
}