#pragma once
#include "VReadDetector.h"
#include "PolygonRegular.h"

class TxtPolygonRegular : public VReadDetector {
public:
	TxtPolygonRegular(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};