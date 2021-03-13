#pragma once
#include "Form.h"


/**
 * @brief Model of the circle
*/
class Circle : public Form
{
private:
	Vector2D _center;
	double _radius;

public:
	/**
	 * @brief Constructor of the circle class
	 * @param center The center of the circle 
	 * @param radius The radius of the circle
	 * @param color  The color of the circle
	*/
	explicit Circle(const Vector2D& center, const double& radius, const Color& color = Color()) : _center(center), _radius(radius), Form(color) { if (radius <= 0) throw Error("Circle radius wrong"); }

	const Vector2D getCenter() const { return _center; }
	const double getRadius() const { return _radius; }

	/**
	 * @brief Calculate the area of the circle
	 * @return The area of the circle
	*/
	virtual const double calculateArea() const { return M_PI * _radius * _radius; }

	/**
	 * @brief Calculate the perimeter of the circle
	 * @return The Perimeter of the circle
	*/
	virtual const double calculatePerimeter() const { return 2 * M_PI * _radius; }

	virtual const Vector2D calculateGravityVector2D() const { return _center; }

	/**
	 * @brief Calculate the size of the window needed to show the entire circle
	 * @return The size of the window needed to show the entire circle 
	*/
	virtual const Vector2D calculateWindowSize() const { return (_center + _radius * Vector2D(1,1)) * 2; }

	/**
	 * @brief Translate the circle
	 * @param vec The vector used for the translation to be made
	*/
	virtual void translate(const Vector2D& vec) { _center += vec; }

	/**
	 * @brief Rotate the circle 
	 * @param radian The angle used for the rotation
	 * @param center The center of the rotation
	*/
	virtual void rotate(const double& radian, const Vector2D& center = Vector2D(0, 0));

	/**
	 * @brief Make an homothety (zoom / zoom out)
	 * @param zoom The factor of the zoom
	 * @param center The focal point of the homothety
	*/
	virtual void homothety(const double& zoom, const Vector2D& center = Vector2D(0, 0)) { _center = ((_center - center) * zoom) + center, _radius *= zoom; }

	/**
	 * @brief Clone the circle
	 * @return The Cloned circle
	*/
	virtual Form* clone() const { return new Circle(*this); }

	/**
	 * @brief Ask for drawing to the visitor
	 * @param visitor The visitor used for the drawing
	 * @param color The color of the circle
	*/
	virtual void draw(const VDraw* visitor, const string& color) const;

	/**
	 * @brief Save the circle in a file using the visitor
	 * @param visitor 
	*/
	virtual void save(VSave* visitor) const;

	virtual operator string() const { ostringstream o; o << "Circle (" << Form::operator string() << "\n         center = " << _center << "\n         radius = " << _radius << ")"; return o.str(); }
};

