#include "VDraw.h"
#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

class VDrawByJavaFX : public VDraw
{
private:
	static const int BORDER = 0;
	static const Vector2D ADDITIONAL_SIZE_WINDOW;
	SOCKET _socket;

public:
	VDrawByJavaFX(bool start = false) { _socket = NULL; if (start) open(); }
	virtual void open();
	virtual void close();
	virtual void resize(const Vector2D& v);
	virtual void clear();
	virtual void sendServer(const char* serializeMessage);

	virtual void draw(const Circle* circle, const string& color);
	virtual void draw(const Segment* segment, const string& color);
	virtual void draw(const PolygonConvex* polygonConvex, const string& color);
	virtual void draw(const GroupForm* groupForm, const string& color);
};