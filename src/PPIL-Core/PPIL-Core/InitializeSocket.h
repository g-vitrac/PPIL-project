#pragma once
#include "Error.h"
#include <winsock2.h>

using namespace std;

/**
 * @brief Initialize a socket
*/
class InitializeSocket
{
private:

	/**
	 * @brief An instance of a socket
	*/
	static InitializeSocket _instance;
	WSADATA WSAData;

	InitializeSocket();
	~InitializeSocket();

public:
	const static InitializeSocket& getInstance() { return _instance; }
};

