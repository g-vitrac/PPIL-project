#include "TxtSegment.h"
#include "VReadByTxt.h"

Form* TxtSegment::detected(string line) const
{
    //On récupère le nom de classe
    string delimiter = "|";
    if (parseParameter(line, delimiter) != "Segment") return NULL;

    //On récupère le vecA
    string strVecA = parseParameter(line, delimiter);
    Vector2D vecA = parseVector(strVecA, string(","));

    //On récupère le vecB
    string strVecB = parseParameter(line, delimiter);
    Vector2D vecB = parseVector(strVecB, string(","));

    //On récupère la couleur
    string color = parseParameter(line, delimiter);

    return new Segment(vecA, vecB, color);
}
