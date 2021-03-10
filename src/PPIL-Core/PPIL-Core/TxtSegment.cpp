#include "TxtSegment.h"
#include "VReadByTxt.h"

Form* TxtSegment::detected(string line) const
{
    //On r�cup�re le nom de classe
    string delimiter = "|";
    if (parseParameter(line, delimiter) != "Segment") return NULL;

    //On r�cup�re le vecA
    string strVecA = parseParameter(line, delimiter);
    Vector2D vecA = parseVector(strVecA, string(","));

    //On r�cup�re le vecB
    string strVecB = parseParameter(line, delimiter);
    Vector2D vecB = parseVector(strVecB, string(","));

    //On r�cup�re la couleur
    string color = parseParameter(line, delimiter);

    return new Segment(vecA, vecB, color);
}
