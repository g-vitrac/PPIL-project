#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "Vector2D.h"

using namespace std;

/**
 * @brief Matrix that is used to rotates the different form
*/
class Matrix22
{
private:
	Vector2D _lineTop;
	Vector2D _lineBottom;

public:
	Matrix22(const double& radian) { _lineTop = Vector2D(cos(radian), -sin(radian)); _lineBottom = Vector2D(sin(radian), cos(radian)); }
	Matrix22(const Vector2D& lineTop, const Vector2D& lineBottom) : _lineTop(lineTop), _lineBottom(lineBottom) {}

	const Vector2D operator* (const Vector2D& v) const { return Vector2D(_lineTop * v, _lineBottom * v); }

	operator string() const { ostringstream o; o << "Matrix ([" << _lineTop << "][" << _lineBottom << "])"; return o.str(); }
};

