#include "Polygon.h"

const vector<Segment*> Polygon::getCollectionSegments() const
{
	return _collectionSegments;
}

const vector<Point*> Polygon::getCollectionPointsToGravity() const
{
	vector<Point*> collectionPoints;
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		collectionPoints.push_back(_collectionSegments[i]->getPointA());
		collectionPoints.push_back(_collectionSegments[i]->getPointB());
	}
	return collectionPoints;
}

const double Polygon::calculatePerimeter() const
{
	return 0;
}

ostream& Polygon::afficher(ostream& o) const
{
	o << "Polygon (";
	Form2D::afficher(o);
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		o << "\n   Segment " << i << " = " << *_collectionSegments[i];
	}
	return o << ")";
}
