#include "Circle.h"

Circle::Circle(int color, Point* centerPoint, double radius)
{
	_color = color;
	_centerPoint = (Point*)centerPoint->clone();
	_radius = radius;
	_area = calculateArea();
	_perimeter = calculatePerimeter();
	_gravityMarking = calculateGravityMarking(getCollectionPointsToGravity());
}

Circle::~Circle()
{
	delete _centerPoint;
}

const Point* Circle::getCenterPoint() const
{
	return _centerPoint;
}

const double Circle::getRadius() const
{
	return _radius;
}

double const Circle::calculateArea() const
{
	return _PI * _radius * _radius;
}

double const Circle::calculatePerimeter() const
{
	return 2 * _PI * _radius;
}

const vector<Point*> Circle::getCollectionPointsToGravity() const
{
	vector<Point*> collectionPoints;
	collectionPoints.push_back(_centerPoint);
	return collectionPoints;
}

Form* Circle::clone() const
{
	Circle* circle = new Circle(*this);
	circle->_centerPoint = (Point*)this->_centerPoint->clone();
	return circle;
}

ostream& Circle::afficher(ostream& o) const
{
	o << "Circle (";
	Form2D::afficher(o);
	return o << "\n     center point = " << *_centerPoint << ",\nradius = " << _radius << ",area = " << _area << ", perimeter = " << _perimeter << ")";
}
