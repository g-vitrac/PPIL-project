#include "Polygon.h"

const vector<Segment*> Polygon::getCollectionSegments() const
{
	return _collectionSegments;
}

ostream& Polygon::afficher(ostream& o) const
{
	o << "Polygon (Segments = ";
	for (unsigned int i = 0; i < _collectionSegments.size(); i++) {
		o << "\n		Segment " << i << " = " << *_collectionSegments[i];
	}
	return o << ")";
}
