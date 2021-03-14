#include "VReadDetector.h"

Form* VReadDetector::detector(string line) const
{
	Form* result = this->detected(line);

	if (result) return result;
	else
		if (this->_next)
			return this->_next->detector(line);
		else										
			return NULL;
}
