#pragma once
#include "Vector2D.h"
#include "Error.h"
#include "Color.h"

#include <iostream>
#include <sstream>
#include <string>
#include <math.h> 
#include <vector>

using namespace std;

class VDraw;
class VSave;
class Form
{
protected:
	Color _color;

public:
	Form* _parentForm; //??????
	static const double M_PI;

	explicit Form(const Color& color) : _color(color), _parentForm(NULL) {}

	const Color& getColor() const { return _color; };

	virtual const double calculateArea() const = 0;
	virtual const double calculatePerimeter() const = 0;
	virtual const Vector2D calculateGravityVector2D() const = 0;
	/**Retourne la largeur et hauteur du plus petit rectangle dont les cotés parralèles aux axes et contenant this
	* abscisse du vector retourné contient largeur et l'ordonnée du vector contient hauteur
	*/
	virtual const Vector2D calculateWindowSize() const = 0;

	virtual void translate(const Vector2D& vec) = 0;
	virtual void rotate(const double& radian, const Vector2D& center = Vector2D()) = 0;
	virtual void homothety(const double& zoom, const Vector2D& center = Vector2D()) = 0;
	Form* translate(const Vector2D& vec) const { Form * clone = this->clone(); clone->translate(vec); return clone; }
	Form* rotate(const double& radian, const Vector2D& center) const { Form* clone = this->clone(); clone->rotate(radian, center); return clone; }
	Form* homothety(const double& zoom, const Vector2D& center) const { Form* clone = this->clone(); clone->homothety(zoom, center); return clone; }

	virtual Form* clone() const = 0;

	virtual void draw(const VDraw* visitor, const string& color) const = 0;
	virtual void save(VSave* visitor) const = 0; //const VSave empeche l'ecriture dans le fichier

	virtual operator string() const { ostringstream o; o << "Form (color = " << (string)_color << ", area = " << calculateArea() << ", perimeter = " << calculatePerimeter() << ", gravity = " << calculateGravityVector2D() << ")"; return o.str(); }
	friend ostream& operator<<(ostream& o, const Form& f) { return o << (string)f; }
};

