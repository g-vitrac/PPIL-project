#include <string>
#include "Error.h"
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
};