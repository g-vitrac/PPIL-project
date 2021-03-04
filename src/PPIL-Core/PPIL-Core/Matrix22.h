#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Matrix22
{
private:
	vector<vector<double>> _matrix;

public:
	Matrix22(const double& x1, const double& x2, const double& y1, const double& y2);

	const vector<vector<double>> getMatrix() const { return _matrix; }

	operator string() const { ostringstream o; o << "Matrix ([" << _matrix[0][0] << "," << _matrix[0][1] << "][" << _matrix[1][0] << "," << _matrix[1][1] << "])"; return o.str(); }
};

