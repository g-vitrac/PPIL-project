#pragma once
#include "Form.h"

/**
 * @brief Model of a polygon
*/
class Polygon : public Form
{
protected:
	vector<Vector2D> _formVecteur2D;

public:
	Polygon(const Color& color = Color()) : Form(color) {}
	Polygon(vector<Vector2D> formVecteur2D, const Color& color = Color());

	const size_t getChildsFormVecteur2D() const { return _formVecteur2D.size(); }
	const Vector2D getPoint(int index) const;

	virtual const double calculatePerimeter() const;
	virtual const Vector2D calculateGravityVector2D() const;
	virtual const Vector2D calculateWindowSize() const { return Vector2D(); }

	virtual void translate(const Vector2D& vec);
	virtual void rotate(const double& radian, const Vector2D& center = Vector2D(0, 0));
	virtual void homothety(const double& zoom, const Vector2D& center = Vector2D(0, 0));

	//virtual void draw(const VDraw* visitor, const string& color) const;
	virtual void save(VSave* visitor) const;

	virtual operator string() const;
};

