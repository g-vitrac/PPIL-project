#pragma once
#include "Form.h"
#include <fstream>

class Detector {
public:
	virtual Form* detector(string line) const = 0;
};
