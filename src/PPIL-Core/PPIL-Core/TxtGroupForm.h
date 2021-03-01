#pragma once
#include "VReadDetector.h"
#include "GroupForm.h"

class TxtGroupForm : public VReadDetector {
public:
	TxtGroupForm(VReadDetector* next) : VReadDetector(next) {}

	virtual Form* detected(string line) const;
};