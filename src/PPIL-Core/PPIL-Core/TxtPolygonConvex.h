#pragma once
#include "VReadDetector.h"
#include "PolygonConvex.h"

class TxtPolygonConvex : public VReadDetector {
public:
	TxtPolygonConvex(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};