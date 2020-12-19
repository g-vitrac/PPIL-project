#pragma once
#include "FormDimension.h"
#include "Segment.h"

class Polygon : public FormDimension
{
protected:
	vector<Segment*> _collectionSegments;

public:
	const vector<Segment*> getCollectionSegments() const;

	virtual ostream& afficher(ostream& o) const;
};

