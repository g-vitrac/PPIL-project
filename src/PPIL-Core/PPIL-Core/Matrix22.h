#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @brief Matrix that is used to rotates the different form
*/
class Matrix22
{
private:
	/**
	 * @brief The matrix used to complete the different calcul
	*/
	vector<vector<double>> _matrix;

public:

	/**
	 * @brief Constructor of the Matrix22 class
	 * @param x1 X coordinate of the first vector used in the rotation
	 * @param x2 X coordinate of the second vector used in the rotation
	 * @param y1 Y coordinate of the first vector used in the rotation
	 * @param y2 Y coordinate of the second vector used in the rotation
	*/
	Matrix22(const double& x1, const double& x2, const double& y1, const double& y2);

	const vector<vector<double>> getMatrix() const { return _matrix; }

	operator string() const { ostringstream o; o << "Matrix ([" << _matrix[0][0] << "," << _matrix[0][1] << "][" << _matrix[1][0] << "," << _matrix[1][1] << "])"; return o.str(); }
};

