#include "Circle.h"
#include "Segment.h"
#include "PolygonConvex.h"
#include "GroupForm.h"
#include <fstream>

class VSave
{
public:
	virtual void open(const string& file) = 0;
	virtual void close() = 0;

	virtual void save(const Circle* circle) = 0;
	virtual void save(const Segment* segment) = 0;
	virtual void save(const PolygonConvex* polygonConvex) = 0;
	virtual void save(const GroupForm* groupForm) = 0;
};