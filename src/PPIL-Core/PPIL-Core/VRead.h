#include "InitializeCor.h"

/**
 * @brief Abstract class that permits the reading of a file
*/
class VRead
{
public:
	static ifstream _fs;

	/**
	 * @brief The read function that use the COR to detect different pattern
	 * @param file The file to read
	 * @return A vector of the form detected inside the file
	*/
	virtual vector<Form*> read(const string& file) = 0;
};
