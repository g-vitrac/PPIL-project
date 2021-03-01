#include "TxtCircle.h"
#include "TxtSegment.h"
#include "TxtGroupForm.h"

class VRead
{
public:
	static ifstream _fs;

	virtual vector<Form*> read(const string& file) = 0;
};
