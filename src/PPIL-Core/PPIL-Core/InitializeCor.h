#pragma once
#include "Error.h"

#include "VReadDetector.h"
#include "TxtCircle.h"
#include "TxtSegment.h"
#include "TxtGroupForm.h"

using namespace std;

/**
 * @brief Initialize the COR design pattern
*/
class InitializeCor
{
private:
	/**
	 * @brief The instance of the singleton representing the cor design pattern
	*/
	static InitializeCor _instance;

	/**
	 * @brief The actual cor
	*/
	VReadDetector* _detectorRead;

	InitializeCor();
	~InitializeCor();

public:
	const static InitializeCor& getInstance() { return _instance; }

	const VReadDetector* getDetectorRead() const { return _detectorRead; }
};

