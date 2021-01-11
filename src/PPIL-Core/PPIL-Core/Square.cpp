#include "Square.h"

Square::Square(int color, vector<Segment*> collectionSegments)
{
	try {
		if (collectionSegments.size() != 4) throw Error("impossible to create square -> number of segment wrong");
		switchCollectionSegmentsWithCheckAndSort(collectionSegments);
		setCollectionSegments(collectionSegments);
		if (isPolygonRegular() == false) throw Error("polygon isn't a regular polygon");
		_color = color;
		_gravityMarking = calculateGravityMarking(getCollectionPointsToGravity());
		_perimeter = calculatePerimeter();
		_area = calculateArea();
	}
	catch (Error const& e) {
		cerr << e << endl;
		delete this;
	}
}

Square::~Square()
{
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		delete _collectionSegments[i];
	}
}

Form* Square::clone() const
{
	Square* square = new Square(*this);
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		square->_collectionSegments[i] = (Segment*)this->_collectionSegments[i]->clone();
	}
	return square;
}

ostream& Square::display(ostream& o) const
{
	o << "Square (";
	PolygonRegular::display(o);
	return o << ")";
}
