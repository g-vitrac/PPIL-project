#pragma once
#include "Form.h"
#include "Point.h"
#include <vector>

class FormDimension : public Form
{
protected:
	Point * _anchorPoint;
	Point * _gravityPoint;

public:
	Point * getAnchorPoint() const;
	Point * getGravityPoint() const;
};

