#pragma 
#include <string>
#include <sstream>
#include <regex>

#include "Error.h"

using namespace std;

/**
 * @brief The classed used to represent the different color
*/

class Color
{
private:
	string _code;

public:
	static const string BLACK;
	static const string BLUE;
	static const string RED;
	static const string GREEN;
	static const string YELLOW;
	static const string CYAN;

	Color(const string& code = BLACK) { setCode(code); }

	const string& getCode() const { return _code; }
	void setCode(const string& code) { if (regex_match(code.c_str(), regex("^#?[0-9a-fA-F]{6}$"))) _code = code; else throw Error("Form : web color doesn't exist"); }

	operator string() const { ostringstream o; o << _code; return o.str(); }
};

