#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <math.h> 
#include <vector>

#include "Vector2D.h"
#include "Matrix22.h"
#include "Error.h"
#include "Color.h"

using namespace std;

class VDraw;
class VSave;
/**
 * @brief The model used to create different shape
*/
class Form
{
protected:
	Color _color;

public:
	Form* _parentForm; //??????
	static const double M_PI;
	explicit Form(const Color& color) : _color(color), _parentForm(NULL) {}

	const Color& getColor() const { return _color; };

	/**
	 * @brief Calculate the area of the form
	 * @return The area of the form
	*/
	virtual const double calculateArea() const = 0;
	
	/**
	 * @brief Calculate the perimeter of the form
	 * @return The perimeter of the form
	*/
	virtual const double calculatePerimeter() const = 0;

	/**
	 * @brief Calculate the center of a form 
	 * @return The center of a shape
	*/
	virtual const Vector2D calculateGravityVector2D() const = 0;


	/**
	 * @brief Calculate the size of the window needed to show the entire form
	 * @return The size of the window needed to show the entire form
	*/
	virtual const Vector2D calculateWindowSize() const = 0;

	/**
	 * @brief Translate the form
	 * @param vec The vector used for the translation to be made
	*/
	virtual void translate(const Vector2D& vec) = 0;

	/**
	 * @brief Rotate the form
	 * @param radian The angle used for the rotation
	 * @param center The center of the rotation
	*/
	virtual void rotate(const double& radian, const Vector2D& center = Vector2D()) = 0;

	/**
	 * @brief Make an homothety (zoom / zoom out)
	 * @param zoom The factor of the zoom
	 * @param center The focal point of the homothety
	*/
	virtual void homothety(const double& zoom, const Vector2D& center = Vector2D()) = 0;
	Form* translateClone(const Vector2D& vec) const { Form * clone = this->clone(); clone->translate(vec); return clone; }
	Form* rotateClone(const double& radian, const Vector2D& center) const { Form* clone = this->clone(); clone->rotate(radian, center); return clone; }
	Form* homothetyClone(const double& zoom, const Vector2D& center) const { Form* clone = this->clone(); clone->homothety(zoom, center); return clone; }

	/**
	 * @brief Clone the form
	 * @return The Cloned form
	*/
	virtual Form* clone() const = 0;

	/**
	 * @brief Ask for drawing to the visitor
	 * @param visitor The visitor used for the drawing
	 * @param color The color of the form
	*/
	virtual void draw(const VDraw* visitor, const string& color) const = 0;

	/**
	 * @brief Save the form in a file using the visitor
	 * @param visitor The visitor used to save form
	*/
	virtual void save(VSave* visitor) const = 0; //const VSave empeche l'ecriture dans le fichier

	virtual operator string() const { ostringstream o; o << "Form (color = " << (string)_color << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ", gravity = " << calculateGravityVector2D() << ")"; return o.str(); }
	friend ostream& operator<<(ostream& o, const Form& f) { return o << (string)f; }
};

