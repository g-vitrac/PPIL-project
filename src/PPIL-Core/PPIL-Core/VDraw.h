#include "Visitor.h"
class VDraw : public Visitor
{
public:
	virtual void open() = 0;
	virtual void close() = 0;

	virtual void draw(Circle* circle) = 0;
	virtual void draw(Segment* segment) = 0;
};