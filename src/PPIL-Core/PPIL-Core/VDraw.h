#include "PolygonG.h"
#include "Circle.h"
#include "Segment.h"
#include "GroupForm.h"

/**
 * @brief Implement the visitor disign pattern for the drawing
*/
class VDraw
{
protected:
	Vector2D _windowSize = Vector2D(1300, 800); //default size of window

public:
	/**
	 * @brief Open a connection with the server used to draw the form, it may be different depending of the
	 * implementation of the visitor design pattern
	*/
	virtual void open() = 0;


	/**
	 * @brief Close the connection with the server used to draw the form, it may be different dependinf of the
	 * implementation of the visitor design pattern
	*/
	virtual void close() = 0;

	/**
	 * @brief Ask to the server to draw a circle
	 * @param circle The circle to draw
	 * @param color The color of the circle
	*/
	virtual void draw(const PolygonG* polygonG, const string& color) const = 0;

	/**
	 * @brief Ask to the server to draw a segment
	 * @param segment The segment to draw
	 * @param color The color of the segment
	*/
	virtual void draw(const Circle* circle, const string& color) const = 0;

	/**
	 * @brief Ask to the server to draw a convex polygon
	 * @param polygon The polygon to draw
	 * @param color The color of the polygon
	*/
	virtual void draw(const Segment* segment, const string& color) const = 0;

	/**
	 * @brief Ask to the server to draw a froup of form
	 * @param groupForm The group of form to draw
	 * @param color The color of the group of form
	*/
	virtual void draw(const GroupForm* groupForm, const string& color) const = 0;
};