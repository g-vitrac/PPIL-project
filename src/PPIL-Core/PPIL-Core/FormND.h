#pragma once
#include "Form.h"
#include "Marking.h"
#include <vector>

class FormND : public Form
{
protected:
	Marking* _anchorMarking;
	Marking* _gravityMarking;

public:
	Marking* getAnchorMarking() const;
	Marking* getGravityMarking() const;

	Marking* calculateGravityMarking(vector<Point*> collection);

	virtual const vector<Point*> getCollectionPointsToGravity() const = 0;

	virtual ostream& display(ostream& o) const;
};

