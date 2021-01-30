#include "VDraw.h"
#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

class VDrawByJavaFX : public VDraw
{
private:
	SOCKET _socket;

public:
	VDrawByJavaFX(bool start = false);
	virtual void open();
	virtual void close();
	virtual void sendServer(const char* serializeMessage);

	virtual void draw(Circle* circle);
	virtual void draw(Segment* segment);
};