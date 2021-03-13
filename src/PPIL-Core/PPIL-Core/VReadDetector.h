#pragma once
#include "Form.h"
#include <fstream>

/**
 * @brief The detector that is used to make the COR design pattern
*/
class VReadDetector
{
	VReadDetector* _next;
public:
	VReadDetector(VReadDetector* next) : _next(next) {}
	~VReadDetector() { 
																//cerr << "Appel à VReadDetector" << endl;
		if (_next) delete _next;
	} 

	/**
	 * @brief The method that try to recognize the good form from a string
	 * by using the detected function
	 * @param line The text from which we try to recognize a pattern to create a form
	 * @return A form that respect the pattern that is wroten in the string
	*/
	virtual Form* detector(string line) const;
	/**
	 * @brief The method that try to detect the different pattern inside the string
	 * @param line The text from which we try to recognize a pattern to create a form
	 * @return A form if the pattern is recognized, else a Null pointer
	*/
	virtual Form* detected(string line) const = 0;
};