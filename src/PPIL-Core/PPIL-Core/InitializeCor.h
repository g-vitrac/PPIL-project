#pragma once
#include "Error.h"

#include "VReadDetector.h"
#include "TxtCircle.h"
#include "TxtSegment.h"
#include "TxtPolygonConvex.h"
#include "TxtPolygonRegular.h"
#include "TxtTriangle.h"
#include "TxtGroupForm.h"

using namespace std;

class InitializeCor
{
private:
	static InitializeCor _instance;
	VReadDetector* _detectorRead;

	InitializeCor();
	~InitializeCor();

public:
	const static InitializeCor& getInstance() { return _instance; }

	const VReadDetector* getDetectorRead() const { return _detectorRead; }
};

