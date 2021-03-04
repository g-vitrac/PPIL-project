#include "InitializeCor.h"

InitializeCor InitializeCor::_instance = InitializeCor();

InitializeCor::InitializeCor() {
	//Cor read
	VReadDetector* rCircle, * rSegment, * rGroupForm;
	rCircle = new TxtCircle(NULL);
	rSegment = new TxtSegment(rCircle);
	rGroupForm = new TxtGroupForm(rSegment);
	_detectorRead = rGroupForm;

	cout << "initializeCor" << endl;
}

InitializeCor::~InitializeCor()
{
	delete _detectorRead;
}