#include "InitializeSocket.h"

InitializeSocket InitializeSocket::_instance = InitializeSocket();

InitializeSocket::InitializeSocket() {
	if (WSAStartup(MAKEWORD(2, 0), &WSAData)) throw Error("L'initialisation a echou�");
	cout << "initializeSocket" << endl;
}

InitializeSocket::~InitializeSocket()
{
	WSACleanup();
}
