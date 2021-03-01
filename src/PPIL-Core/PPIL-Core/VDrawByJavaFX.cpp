#include "VDrawByJavaFX.h"

const Vector2D VDrawByJavaFX::ADDITIONAL_SIZE_WINDOW = Vector2D(16, 39);

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
    resize(_windowSize);
}

void VDrawByJavaFX::close()
{
    if (shutdown(_socket, SD_BOTH) == SOCKET_ERROR) throw Error("La coupure de connexion a echoué");
    if (closesocket(_socket)) throw Error("Deconnexion au serveur impossible");
    WSACleanup();
}

void VDrawByJavaFX::resize(const Vector2D& v)
{
    _windowSize = v;
    sendServer(_strdup(("Resize," + (_windowSize + ADDITIONAL_SIZE_WINDOW).serialize() + "\n").c_str()));
}

void VDrawByJavaFX::clear()
{
    sendServer(_strdup("Clear\n"));
}

void VDrawByJavaFX::sendServer(const char* serializeMessage)
{
    if (send(_socket, serializeMessage, (int)strlen(serializeMessage), 0) < 0) throw Error("Erreur envoie du message");
}

void VDrawByJavaFX::draw(const Circle* circle, const string& color)
{
    string className = "Circle";
    string center = (circle->getCenter() + (_windowSize / 2)).serialize();
    string radius = to_string(circle->getRadius());
    sendServer(_strdup((className + "," + center + "," + radius + "," + color + "\n").c_str()));
}

void VDrawByJavaFX::draw(const Segment* segment, const string& color)
{
    string className = "Segment";
    string vecA = (segment->getVecA() + (_windowSize / 2)).serialize();
    string vecB = (segment->getVecB() + (_windowSize / 2)).serialize();
    sendServer(_strdup((className + "," + vecA + "," + vecB + "," + color + "\n").c_str()));
}

void VDrawByJavaFX::draw(const PolygonConvex* polygonConvex, const string& color)
{
}

void VDrawByJavaFX::draw(const GroupForm* groupForm, const string& color)
{
    for (int i = 0; i < groupForm->getChildsFormSize(); i++) {
        groupForm->getChild(i)->draw(this, color);
    }
}
