#include "Circle.h"
#include "Segment.h"
#include "PolygonConvex.h"
#include "GroupForm.h"

class VDraw
{
protected:
	Vector2D _windowSize = Vector2D(1300, 800); //default size of window

public:
	virtual void open() = 0;
	virtual void close() = 0;

	virtual void draw(const Circle* circle, const string& color) = 0;
	virtual void draw(const Segment* segment, const string& color) = 0;
	virtual void draw(const PolygonConvex* polygonConvex, const string& color) = 0;
	virtual void draw(const GroupForm* groupForm, const string& color) = 0;
};