#pragma once
#include "Detector.h"

class VReadDetector : public Detector
{
	VReadDetector* _next;
public:
	VReadDetector(VReadDetector* next) : _next(next) {}

	virtual Form* detector(string line) const;
	virtual Form* detected(string line) const = 0;
};