#include "Circle.h"
#include "Segment.h"
#include "PolygonConvex.h"
#include "GroupForm.h"

class Visitor
{
public:
	//Draw
	virtual void draw(const Circle* circle, const string& color) = 0;
	virtual void draw(const Segment* segment, const string& color) = 0;
	virtual void draw(const PolygonConvex* polygonConvex, const string& color) = 0;
	virtual void draw(const GroupForm* groupForm, const string& color) = 0;

	//Save
	virtual void save(const Circle* circle) = 0;
	virtual void save(const Segment* segment) = 0;
	virtual void save(const PolygonConvex* polygonConvex) = 0;
	virtual void save(const GroupForm* groupForm) = 0;
};