#include "VDraw.h"
#include <QApplication>
#include <QPushButton>

class VDrawByQt : public VDraw
{
public:
	explicit VDrawByQt(bool start = false);
	virtual void open();
	virtual void close();
	virtual void sendServer(const char* serializeMessage);

	virtual void draw(Circle* circle);
	virtual void draw(Segment* segment);
	virtual void draw(PolygonConvex* polygonConvex);
};