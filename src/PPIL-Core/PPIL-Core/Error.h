#pragma once
#include <exception>
#include <string>
#include <iostream>

using namespace std;

class Error : public exception
{
protected:
	char* _message;
	int _number;
	int _priority;

public:
	Error() throw();
	Error(const char* message) throw();
	Error(const char* message, int number, int priority) throw();
	~Error();

	const char* getMessage() const;
	const int getNumber() const;
	const int getPriority() const;

	friend ostream& operator<<(ostream& o, const Error& e) throw();
	virtual ostream& display(ostream& o) const throw();
};


