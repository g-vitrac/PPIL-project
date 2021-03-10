#pragma once
#include "VReadDetector.h"
#include "Segment.h"

/**
 * @brief The expert that detects segment
*/
class TxtSegment : public VReadDetector {
public:
	TxtSegment(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};
