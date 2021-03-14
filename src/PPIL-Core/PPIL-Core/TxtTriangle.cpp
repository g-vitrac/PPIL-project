#include "TxtTriangle.h"
#include "VReadByTxt.h"

Form* TxtTriangle::detected(string line) const
{
    //On r�cup�re le nom de classe
    string delimiter = "|";
    if (parseParameter(line, delimiter) != "Triangle") return NULL;

    //On r�cup�re les points
    vector<string> parameters = parseParameters(line, delimiter);
    vector<Vector2D> vectors = parseVectors(parameters, string(","), 0, ((int)parameters.size()) - 1);

    //On r�cup�re la couleur
    string color = parameters[parameters.size() - 1];

    return new Triangle(vectors, color);
}
