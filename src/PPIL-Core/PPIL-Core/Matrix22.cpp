#include "Matrix22.h"

Matrix22::Matrix22(const double& x1, const double& x2, const double& y1, const double& y2)
{
	vector<double> x, y;
	x.push_back(x1); x.push_back(x2);
	y.push_back(y1); y.push_back(y2);
	_matrix.push_back(x); _matrix.push_back(y);
}
