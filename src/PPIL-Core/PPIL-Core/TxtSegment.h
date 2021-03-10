#pragma once
#include "VReadDetector.h"
#include "Segment.h"

class TxtSegment : public VReadDetector {
public:
	TxtSegment(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};
