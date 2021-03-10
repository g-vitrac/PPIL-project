#include "InitializeCor.h"

class VRead
{
public:
	static ifstream _fs;

	virtual vector<Form*> read(const string& file) = 0;
};
