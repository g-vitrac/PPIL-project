#pragma once
#include "VReadDetector.h"
#include "Circle.h"

/**
 * @brief The expert that detects circles
*/
class TxtCircle : public VReadDetector {
public:
	TxtCircle(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};