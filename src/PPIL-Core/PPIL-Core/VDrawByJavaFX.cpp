#include "VDrawByJavaFX.h"

VDrawByJavaFX::VDrawByJavaFX(bool start)
{
    _sizeWindow = 400;
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

void VDrawByJavaFX::resize(const Form* form)
{
    _sizeWindow = form->calculateWindowSize(Vecteur2D(0,0)) + BORDER;
    sendServer(_strdup(("Resize," + to_string(_sizeWindow) + "\n").c_str()));
}

void VDrawByJavaFX::clear()
{
    sendServer(_strdup("Clear\n"));
}

void VDrawByJavaFX::sendServer(const char* serializeMessage)
{
    if (send(_socket, serializeMessage, strlen(serializeMessage), 0) < 0) throw Error("Erreur envoie du message");
}

void VDrawByJavaFX::draw(Circle* circle)
{
    string className = ("Circle");
    cout << _sizeWindow << endl;
    string posX = to_string((int)round(circle->getCenter().getPosX() + (_sizeWindow / 2)));
    string poxY = to_string((int)round(circle->getCenter().getPosY() + (_sizeWindow / 2)));
    string radius = to_string((int)round(circle->getRadius()));
    sendServer(_strdup((className + "," + posX + "," + poxY + "," + radius + "\n").c_str()));
}

void VDrawByJavaFX::draw(Segment* segment)
{
    string className = ("Segment");
    cout << _sizeWindow << endl;
    string posX_A = to_string((int)round(segment->getVecA().getPosX() + (_sizeWindow / 2)));
    string poxY_A = to_string((int)round(segment->getVecA().getPosY() + (_sizeWindow / 2)));
    string posX_B = to_string((int)round(segment->getVecB().getPosX() + (_sizeWindow / 2)));
    string poxY_B = to_string((int)round(segment->getVecB().getPosY() + (_sizeWindow / 2)));
    /*
    string posX_A = to_string(segment->getVecA().getPosX());
    string poxY_A = to_string(segment->getVecA().getPosY());
    string posX_B = to_string(segment->getVecB().getPosX());
    string poxY_B = to_string(segment->getVecB().getPosY());
    */
    sendServer(_strdup((className + "," + posX_A + "," + poxY_A + "," + posX_B + "," + poxY_B + "\n").c_str()));
}

void VDrawByJavaFX::draw(PolygonConvex* polygonConvex)
{
}
