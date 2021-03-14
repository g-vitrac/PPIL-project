#pragma once
#include "Form.h"

class World
{
private:
	Form* _rootForm;

public:
	World(Form* rootForm);
	~World();

	const Form* getRootForm() const;
};
extern ostream& operator<<(ostream& o, const World& w);


