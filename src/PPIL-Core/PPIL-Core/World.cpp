#include "World.h"

World::World(Form* rootForm)
{
	_rootForm = rootForm;
}

World::~World()
{
	delete _rootForm;
}

const Form* World::getRootForm() const
{
	return _rootForm;
}

ostream& operator<<(ostream& o, const World& w)
{
	o << "World (" << "root form = " << *w.getRootForm();
	return o << ")";
}
