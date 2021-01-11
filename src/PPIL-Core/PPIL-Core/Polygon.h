#pragma once
#include "Form2D.h"
#include "Segment.h"

class Polygon : public Form2D
{
protected:
	vector<Segment*> _collectionSegments;

public:
	const vector<Segment*> getCollectionSegments() const;
	void setCollectionSegments(vector<Segment*> collectionSegments);
	void switchCollectionSegmentsWithCheckAndSort(vector<Segment*> & collectionSegments);
	
	virtual const double calculatePerimeter() const;
	virtual const vector<Point*> getCollectionPointsToGravity() const;

	virtual ostream& display(ostream& o) const;
};

