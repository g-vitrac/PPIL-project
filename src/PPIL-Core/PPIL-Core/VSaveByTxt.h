#include "VSave.h"

class VSaveByTxt : public VSave
{
private:
	ofstream _fs;

public:
	virtual void open(const string& file);
	virtual void close();

	virtual void save(const Circle* circle);
	virtual void save(const Segment* segment);
	virtual void save(const Polygon* polygon);
	virtual void save(const GroupForm* groupForm);
};