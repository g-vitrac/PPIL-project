#pragma once
#include "VRead.h"


class VReadByTxt : public VRead
{
public:
	virtual vector<Form*> read(const string& file);
	Form* parse(string line);
};