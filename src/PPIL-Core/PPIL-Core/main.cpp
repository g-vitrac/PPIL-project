#include "Point.h"
#include "Segment.h"
#include "Circle.h"
#include "Square.h"
#include <vector>

using namespace std;

int main() {
	Point* pointA = new Point(Form::BLUE, 0, 2);
	//cout << *pointA << endl;
	Point* pointB = new Point(Form::GREEN, 4, 3);
	//cout << *pointB << endl;
	Point* pointC = new Point(Form::BLUE, 4, 7);
	//cout << *pointA << endl;
	Point* pointD = new Point(Form::GREEN, 0, 7);
	//cout << *pointB << endl;

	Segment* segmentA = new Segment(Form::RED, pointA, pointB);
	//cout << *segmentA << endl;
	Segment* segmentB = new Segment(Form::CYAN, pointB, pointC);
	//cout << *segmentB << endl;
	Segment* segmentC = new Segment(Form::YELLOW, pointC, pointD);
	//cout << *segmentA << endl;
	Segment* segmentD = new Segment(Form::GREEN, pointD, pointA);
	//cout << *segmentB << endl;

	vector<Segment*> _collectionSegments;
	_collectionSegments.push_back(segmentA);
	_collectionSegments.push_back(segmentB);
	_collectionSegments.push_back(segmentC);
	_collectionSegments.push_back(segmentD);

	Square* square = new Square(Form::RED, _collectionSegments);
	//cout << *square << endl;

	Circle* circle = new Circle(Form::RED, pointC, 3);
	//cout << *circle << endl;

	delete pointA, pointB, pointC, pointD, segmentA, segmentB, segmentC, segmentD;
	//cout << *square << endl;
}