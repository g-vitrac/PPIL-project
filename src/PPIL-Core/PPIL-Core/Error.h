#pragma once
#include <exception>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Error : public exception
{
protected:
	string _message;
	int _number;
	int _priority;

public:
	Error() throw() : _message("NULL MESSAGE"), _number(-1), _priority(-1) {}
	Error(const char* message) throw() : _message((string)message), _number(-1), _priority(-1) {}
	Error(const char* message, int number, int priority) throw() : _message((string)message), _number(-1), _priority(-1) {}

	const string getMessage() const { return _message; }
	const int getNumber() const { return _number; }
	const int getPriority() const { return _priority; }

	virtual operator string() const { ostringstream o; o << "Error (message = " << _message << ", number = " << _number << ", priority = " << _priority << ")"; return o.str(); }
	friend ostream& operator<<(ostream& o, const Error& e) throw() { return o << (string)e; }
};


