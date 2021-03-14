#include "TxtCircle.h"
#include "VReadByTxt.h"

Form* TxtCircle::detected(string line) const
{
    //On r�cup�re le nom de classe
    string delimiter = "|";
    if (parseParameter(line, delimiter) != "Circle") return NULL;

    //On r�cup�re le centre
    string strCenter = parseParameter(line, delimiter);
    Vector2D center = parseVector(strCenter, string(","));

    //On r�cup�re le rayon
    string strRadius = parseParameter(line, delimiter);
    double radius = atof(strRadius.c_str());

    //On r�cup�re la couleur
    string color = parseParameter(line, delimiter);

    return new Circle(center, radius, color);
}
