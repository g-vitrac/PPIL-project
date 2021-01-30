#include "Error.h"

Error::Error() throw()
{
	_message = _strdup("NULL MESSAGE");
	_number = -1;
	_priority = -1;
}

Error::Error(const char* message) throw()
{
	_message = _strdup(message);
	_number = -1;
	_priority = -1;
}

Error::Error(const char* message, int number, int priority) throw()
{
	_message = _strdup(message);
	_number = number;
	_priority = priority;
}

Error::~Error()
{
}

const char* Error::getMessage() const
{
	return _message;
}

const int Error::getNumber() const
{
	return _number;
}

const int Error::getPriority() const
{
	return _priority;
}

ostream& Error::display(ostream& o) const throw()
{
	return o << "ERROR (message = " << _message << ", number = " << _number << ", priority = " << _priority <<  ")";
}

ostream& operator<<(ostream& o, const Error& c) throw()
{
	return c.display(o);
}