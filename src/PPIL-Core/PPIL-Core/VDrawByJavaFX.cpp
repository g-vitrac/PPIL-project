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
    if (shutdown(_socket, SD_BOTH) == SOCKET_ERROR) throw Error("La coupure de connexion a echou�");
    if (closesocket(_socket)) throw Error("Deconnexion au serveur impossible");
}

void VDrawByJavaFX::resize(const Vector2D& v)
{
    _windowSize = v;
    sendServer("Resize," + (_windowSize + ADDITIONAL_SIZE_WINDOW).serialize() + "\n");
}

void VDrawByJavaFX::clear()
{
    sendServer("Clear\n");
}

void VDrawByJavaFX::sendServer(const string& serializeMessage) const
{
    const char* message = serializeMessage.c_str();
    if (send(_socket, message, (int)strlen(message), 0) < 0) throw Error("Error to send socket");
}

void VDrawByJavaFX::draw(const Circle* circle, const string& color) const
{
    string className = "Circle";
    string center = (circle->getCenter().center(_windowSize).serialize());
    string radius = to_string(circle->getRadius());
    sendServer(className + "," + center + "," + radius + "," + color + "\n");
}

void VDrawByJavaFX::draw(const Segment* segment, const string& color) const
{
    string className = "Segment";
    string vecA = (segment->getVecA().center(_windowSize).serialize());
    string vecB = (segment->getVecB().center(_windowSize).serialize());
    sendServer(className + "," + vecA + "," + vecB + "," + color + "\n");
}

void VDrawByJavaFX::draw(const PolygonG* polygonG, const string& color) const
{
    vector<Vector2D> vectors = centerVectors2D(polygonG->getFormVecteur2D(), _windowSize);
    string result = "PolygonG," + serializeVectors2D(vectors, string(","));   
    sendServer(result + "," + color + "\n");
}

void VDrawByJavaFX::draw(const GroupForm* groupForm, const string& color) const
{
    for (int i = 0; i < groupForm->getChildsFormSize(); i++) {
        groupForm->getChild(i)->draw(this, color);
    }
}
