#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Error.h"

using namespace std;

/**
 * @brief Can either be the model of a point or a vector used in the different operations on the form class
*/
class Vector2D
{
private:
	double _posX;
	double _posY;

public:
	explicit Vector2D() : _posX(0), _posY(0) {}
	explicit Vector2D(double pos) : _posX(pos), _posY(pos) {}
	explicit Vector2D(double posX, double posY) : _posX(posX), _posY(posY) {}

	const double getPosX() const { return _posX; }
	const double getPosY() const { return _posY; }

	/**
	 * @brief override the * operator for the vector, thus implementing the scalar product.
	 * @param v the second vector of the scalar product.
	 * @return the scalar product of this and v.
	*/
	const double operator* (const Vector2D& v) const { return _posX * v._posX + _posY * v._posY; }
	const Vector2D operator* (const double& d) const { return Vector2D(_posX * d, _posY * d); }
	const Vector2D& operator*= (const double& d) { return *this = *this * d; }

	const Vector2D operator+ (const Vector2D& v) const { return Vector2D(_posX + v._posX, _posY + v._posY); }
	const Vector2D& operator+= (const Vector2D& v) { return *this = *this + v; }

	const Vector2D operator- () const { return Vector2D(-_posX, -_posY); }
	const Vector2D operator- (const Vector2D& v) const { return *this + -v; }

	const Vector2D operator/ (const double& d) const { return *this * (1 / d); }

	const double norm() const { return sqrt(*this * *this); }
	const double distance(const Vector2D& v) const { return (*this - v).norm(); }
	const double determinant(const Vector2D& v) const { return (_posX * v._posY) - (_posY * v._posX); }

	/**
	 * @brief Find the highest value in the coordinate from two vectors.
	 * @param v the other vector that is checked for the highest value.
	 * @return A new vector using the highest coordinate between this and v.
	*/
	const Vector2D maximum(const Vector2D& v) const { return Vector2D(max(abs(_posX), abs(v._posX)), max(abs(_posY), abs(v._posY))); }

	/**
	 * @brief Centers the vector on the window.
	 * @param windowSize The size of the window.
	 * @return The new centered vector.
	*/
	const Vector2D center(const Vector2D& windowSize) const { return (*this + (windowSize / 2)); }
	const string serialize() const { return to_string(_posX) + "," + to_string(_posY); }

	operator string() const { ostringstream o; o << "Vector2D(" << _posX << "," << _posY << ")"; return o.str(); }
};
inline const Vector2D operator* (const double& d, const Vector2D& v) { return v * d; }
inline ostream& operator<<(ostream& o, const Vector2D& v) { return o << (string)v; }

/**
 * @brief Centers all the vectors.
 * @param vectors The vectors inside the window.
 * @param windowSize The size of the window.
 * @return The new centered vectors.
*/
inline const vector<Vector2D> centerVectors2D(const vector<Vector2D>& vectors, const Vector2D& windowSize) {
	vector<Vector2D> result;
	for (unsigned int i = 0; i < vectors.size(); i++) {
		result.push_back(vectors[i].center(windowSize));
	}
	return result;
}

/**
 * @brief Serialize the vectors.
 * @param vectors The list of vector that needs to be serialized.
 * @param delimeter The string that will delimite two field of the final
 * serialized vectors.
 * @return The serialized vectors.
*/
inline const string serializeVectors2D(const vector<Vector2D>& vectors, const string& delimeter) {
	size_t size = vectors.size();
	if (size < 1) throw Error("serializeVectors2D : vectors empty");
	string result = "";
	int i;
	for (i = 0; i < vectors.size() - 1; i++) {
		result += vectors[i].serialize() + delimeter;
	}
	return result += vectors[i].serialize();
}

