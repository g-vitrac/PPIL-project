#include "Square.h"

Square::Square(int color, vector<Segment*> collectionSegments)
{
	_color = color;
	for (unsigned int i = 0; i < collectionSegments.size(); i++) {
		_collectionSegments.push_back((Segment*)collectionSegments[i]->clone());
	}
	_gravityMarking = calculateGravityMarking(getCollectionPointsToGravity());
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

ostream& Square::afficher(ostream& o) const
{
	o << "Square (";
	PolygonRegular::afficher(o);
	return o << ")";
}
