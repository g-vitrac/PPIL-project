#pragma once
#include "VReadDetector.h"
#include "Circle.h"

class TxtCircle : public VReadDetector {
public:
	TxtCircle(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};