#pragma once
#include "Error.h"
#include <winsock2.h>

using namespace std;

class InitializeSocket
{
private:
	static InitializeSocket _instance;
	WSADATA WSAData;

	InitializeSocket();
	~InitializeSocket();

public:
	const static InitializeSocket& getInstance() { return _instance; }
};

