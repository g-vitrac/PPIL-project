#include "VDrawByJavaFX.h"

VDrawByJavaFX::VDrawByJavaFX(bool start)
{
    if (start) open();
}

void VDrawByJavaFX::open() {
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");

    hello.show();
    return app.exec();
}

void VDrawByJavaFX::close()
{

}

void VDrawByJavaFX::draw(Circle* circle)
{
    string className = ("Circle");
    string posX = to_string(circle->getCenter().getPosX());
    string poxY = to_string(circle->getCenter().getPosY());
    string radius = to_string(circle->getRadius());
    sendServer(_strdup((className + "," + posX + "," + poxY + "," + radius + "\n").c_str()));
}

void VDrawByJavaFX::draw(Segment* segment)
{
    string className = ("Segment");
    string posX_A = to_string(segment->getVecA().getPosX());
    string poxY_A = to_string(segment->getVecA().getPosY());
    string posX_B = to_string(segment->getVecB().getPosX());
    string poxY_B = to_string(segment->getVecB().getPosY());
    sendServer(_strdup((className + "," + posX_A + "," + poxY_A + "," + posX_B + "," + poxY_B + "\n").c_str()));
}

void VDrawByJavaFX::draw(PolygonConvex* polygonConvex)
{
}
