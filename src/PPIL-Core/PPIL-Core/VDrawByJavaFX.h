#include "VDraw.h"
#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

class VDrawByJavaFX : public VDraw
{
private:
	static const int BORDER = 0;
	SOCKET _socket;
	int _sizeWindow;

public:
	explicit VDrawByJavaFX(bool start = false);
	virtual void open();
	virtual void close();
	virtual void resize(const Form* form);
	virtual void clear();
	virtual void sendServer(const char* serializeMessage);

	virtual void draw(Circle* circle);
	virtual void draw(Segment* segment);
	virtual void draw(PolygonConvex* polygonConvex);
};