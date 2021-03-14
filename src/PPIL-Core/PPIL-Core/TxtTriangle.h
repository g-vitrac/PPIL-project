#pragma once
#include "VReadDetector.h"
#include "Triangle.h"

class TxtTriangle : public VReadDetector {
public:
	TxtTriangle(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};