#include "Polygon.h"

const vector<Segment*> Polygon::getCollectionSegments() const
{
	return _collectionSegments;
}

void Polygon::setCollectionSegments(vector<Segment*> collectionSegments) {
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		delete _collectionSegments[i];
	}
	for (unsigned int i = 0; i < collectionSegments.size(); i++) {
		_collectionSegments.push_back((Segment*)collectionSegments[i]->clone());
	}
}

void Polygon::switchCollectionSegmentsWithCheckAndSort(vector<Segment*> & collectionSegments)
{
	int maxCount = collectionSegments.size();
	int count = 1;
	bool isCheck = false;
	while (count < maxCount) {
		for (unsigned int i = count; i < collectionSegments.size(); i++) {
			cerr << "\nSEGMENT 1 : " << *collectionSegments[count - 1] << "\nSEGMENT 2 : " << *collectionSegments[i] << endl;
			if (collectionSegments[count-1]->isAdjacentSides(collectionSegments[i])) {
				iter_swap(collectionSegments.begin() + i, collectionSegments.begin() + count);
				isCheck = true;
				break;
			}
		}
		if (isCheck == false) throw Error("vector of segment isn't a polygon");
		count++;
	}
	cerr << "\nSEGMENT 1 : " << *collectionSegments[count - 1] << "\nSEGMENT 2 : " << *collectionSegments[0] << endl;
	if (collectionSegments[count-1]->isAdjacentSides(collectionSegments[0]) == false) throw Error("vector of segment isn't a polygon");
}

const vector<Point*> Polygon::getCollectionPointsToGravity() const
{
	//C'est faux
	vector<Point*> collectionPoints;
	collectionPoints.push_back(_collectionSegments[0]->getPointA());
	collectionPoints.push_back(_collectionSegments[0]->getPointB());
	for (unsigned int i = 1; i < _collectionSegments.size(); i++) {
		collectionPoints.push_back(_collectionSegments[i]->getPointA());
		collectionPoints.push_back(_collectionSegments[i]->getPointB());
	}
	return collectionPoints;
}

const double Polygon::calculatePerimeter() const
{
	double somme = 0;
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		somme += _collectionSegments[i]->calculateDistance();
	}
	return somme;
}

ostream& Polygon::display(ostream& o) const
{
	o << "Polygon (";
	Form2D::display(o);
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		o << "\n   Segment " << i << " = " << *_collectionSegments[i];
	}
	return o << ")";
}
