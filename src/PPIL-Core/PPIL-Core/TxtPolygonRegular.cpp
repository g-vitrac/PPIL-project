#include "TxtPolygonRegular.h"
#include "VReadByTxt.h"

Form* TxtPolygonRegular::detected(string line) const
{
    //On récupère le nom de classe
    string delimiter = "|";
    if (parseParameter(line, delimiter) != "PolygonRegular") return NULL;

    //On récupère les points
    vector<string> parameters = parseParameters(line, delimiter);
    vector<Vector2D> vectors = parseVectors(parameters, string(","), 0, ((int)parameters.size()) - 1);

    //On récupère la couleur
    string color = parameters[parameters.size() - 1];

    return new PolygonRegular(vectors, color);
}
