#include "VDrawByJavaFX.h"

VDrawByJavaFX::VDrawByJavaFX(bool start)
{
	if (start) open();
}

void VDrawByJavaFX::open() {
    WSADATA WSAData;
    SOCKADDR_IN sin;
    int protocole = IPPROTO_TCP;
    if (WSAStartup(MAKEWORD(2, 0), &WSAData)) throw Error("L'initialisation a echoué");
    _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    inet_pton(AF_INET, "127.0.0.1", &sin.sin_addr.s_addr);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(9111);
    if (connect(_socket, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR) throw Error("Connexion au serveur impossible");
}

void VDrawByJavaFX::close()
{
    if (shutdown(_socket, SD_BOTH) == SOCKET_ERROR) throw Error("La coupure de connexion a echoué");
    if (closesocket(_socket)) throw Error("Deconnexion au serveur impossible");
    WSACleanup();
}

void VDrawByJavaFX::sendServer(const char* serializeMessage)
{
    if (send(_socket, serializeMessage, strlen(serializeMessage), 0) < 0) throw Error("Erreur envoie du message");
}

void VDrawByJavaFX::draw(Circle* circle)
{
    string className = ("Circle");
    string posX = to_string(circle->getVecteur2DByIndex(0).getPosX());
    string poxY = to_string(circle->getVecteur2DByIndex(0).getPosY());
    string radius = to_string(circle->getRadius());
    sendServer(_strdup((className + "," + posX + "," + poxY + "," + radius + "\n").c_str()));
}

void VDrawByJavaFX::draw(Segment* segment)
{
    string className = ("Segment");
    string posX_A = to_string(segment->getVecteur2DByIndex(0).getPosX());
    string poxY_A = to_string(segment->getVecteur2DByIndex(0).getPosY());
    string posX_B = to_string(segment->getVecteur2DByIndex(1).getPosX());
    string poxY_B = to_string(segment->getVecteur2DByIndex(1).getPosY());
    sendServer(_strdup((className + "," + posX_A + "," + poxY_A + "," + posX_B + "," + poxY_B + "\n").c_str()));
}
