#pragma once
#include "Form.h"
#include <fstream>

class VReadDetector
{
	VReadDetector* _next;
public:
	VReadDetector(VReadDetector* next) : _next(next) {}
	~VReadDetector() { delete _next; }

	virtual Form* detector(string line) const;
	virtual Form* detected(string line) const = 0;
};