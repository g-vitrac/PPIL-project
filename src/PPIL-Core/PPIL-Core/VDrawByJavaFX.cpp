#include "VDrawByJavaFX.h"

const Vector2D VDrawByJavaFX::ADDITIONAL_SIZE_WINDOW = Vector2D(16, 39);

void VDrawByJavaFX::open() {
    SOCKADDR_IN sin;
    int protocole = IPPROTO_TCP;
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
}

void VDrawByJavaFX::resize(const Vector2D& v)
{
    _windowSize = v;
    sendServer(("Resize," + (_windowSize + ADDITIONAL_SIZE_WINDOW).serialize() + "\n").c_str());
}

void VDrawByJavaFX::clear()
{
    sendServer("Clear\n");
}

void VDrawByJavaFX::sendServer(const char* serializeMessage) const
{
    if (send(_socket, serializeMessage, (int)strlen(serializeMessage), 0) < 0) throw Error("Error to send socket");
}

void VDrawByJavaFX::draw(const Circle* circle, const string& color) const
{
    string className = "Circle";
    string center = (circle->getCenter().centerVector2D(_windowSize));
    string radius = to_string(circle->getRadius());
    sendServer((className + "," + center + "," + radius + "," + color + "\n").c_str());
}

void VDrawByJavaFX::draw(const Segment* segment, const string& color) const
{
    string className = "Segment";
    string vecA = (segment->getVecA().centerVector2D(_windowSize));
    string vecB = (segment->getVecB().centerVector2D(_windowSize));
    sendServer((className + "," + vecA + "," + vecB + "," + color + "\n").c_str());
}

void VDrawByJavaFX::draw(const PolygonConvex* polygon, const string& color) const
{
    string result = "Polygon";   
    for (int i = 0; i < polygon->getChildsFormVecteur2D(); i++) {
        result += "," + polygon->getPoint(i).centerVector2D(_windowSize);
    }
    sendServer((result + "," + color + "\n").c_str());
}

void VDrawByJavaFX::draw(const GroupForm* groupForm, const string& color) const
{
    for (int i = 0; i < groupForm->getChildsFormSize(); i++) {
        groupForm->getChild(i)->draw(this, color);
    }
}
