#include "InitializeCor.h"

InitializeCor InitializeCor::_instance = InitializeCor();

InitializeCor::InitializeCor() {
	//Cor read
	VReadDetector* rCircle, * rSegment, * rGroupForm, * rPolygonConvex, * rTriangle, * rPolygonRegular;
	rCircle = new TxtCircle(NULL);
	rSegment = new TxtSegment(rCircle);
	rGroupForm = new TxtGroupForm(rSegment);
	rPolygonConvex = new TxtPolygonConvex(rGroupForm);
	rTriangle = new TxtTriangle(rPolygonConvex);
	rPolygonRegular = new TxtPolygonRegular(rTriangle);
	_detectorRead = rPolygonRegular;

	cout << "initializeCor" << endl;
}

InitializeCor::~InitializeCor()
{
	delete _detectorRead;
}