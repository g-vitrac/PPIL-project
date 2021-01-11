#pragma once
#include "PolygonRegular.h"
class Square : public PolygonRegular
{
public:
	Square(int color, vector<Segment*> collectionSegments);
	~Square();

	virtual Form* clone() const;

	virtual ostream& display(ostream& o) const;
};

