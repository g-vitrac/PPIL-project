#include "Triangle.h"
#include "VSave.h"

void Triangle::save(VSave* visitor) const
{
	visitor->save(this);
}
