#pragma once
#include "Form.h"

/**
 * @brief This class makes possible the creation of group of form
 */
class GroupForm : public Form
{
private:
	/**
	 * @brief A vector of child that belongs to the group of form
	*/
	vector<Form*> _childsForm; 

public:
	GroupForm(const Color& color = Color()) : Form(color) {}
	~GroupForm();

	
	const size_t getChildsFormSize() const { return _childsForm.size(); }

	const Form* getChild(int index) const;

	virtual const double calculateArea() const;
	virtual const double calculatePerimeter() const;
	virtual const Vector2D calculateGravityVector2D() const;
	virtual const Vector2D calculateWindowSize() const;

	void insertChild(Form* form);
	void removeChild(int index);

	/**
	 * @brief Replace the node that is used in the tree that host all the other form / group of form
	 * @param form The form that will replace the current "father" of this group of form
	*/
	void replaceNode(Form* form);

	virtual void translate(const Vector2D& vec);
	virtual void rotate(const double& degrees, const Vector2D& center = Vector2D(0, 0));
	virtual void homothety(const double& zoom, const Vector2D& center = Vector2D(0, 0));

	virtual Form* clone() const;

	virtual void draw(const VDraw* visitor, const string& color) const;
	virtual void save(VSave* visitor) const;

	virtual operator string() const;
};
