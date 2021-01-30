#include <string>
#include "Error.h"
#include "Circle.h"
#include "Segment.h"

class Visitor
{
public:
	//Draw
	virtual void draw(Circle* circle) = 0;
	virtual void draw(Segment* segment) = 0;

	//Transform
	/* ?????,
	virtual void translate(Circle* circle) = 0;
	virtual void rotate(Circle* circle) = 0;
	virtual void homothety(Circle* circle) = 0;
	*/
};