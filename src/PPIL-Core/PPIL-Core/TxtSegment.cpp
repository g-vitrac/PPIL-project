#include "TxtSegment.h"

Form* TxtSegment::detected(string line) const
{
    size_t pos = 0;

    //On récupère le nom de classe
    pos = line.find("|");
    if (line.substr(0, pos) != "Segment") return NULL;
    line.erase(0, pos + string("|").length());

    vector<string> split;
    while ((pos = line.find("|")) != std::string::npos) {
        split.push_back(line.substr(0, pos));
        line.erase(0, pos + string("|").length());
    }
    split.push_back(line);

    //On récupère le vecA
    double x = atof(split[0].substr(0, split[0].find(",")).c_str());
    double y = atof(split[0].substr(split[0].find_last_of(',') + 1).c_str());
    Vector2D vecA = Vector2D(x, y);

    //On récupère le vecB
    x = atof(split[1].substr(0, split[1].find(",")).c_str());
    y = atof(split[1].substr(split[1].find_last_of(',') + 1).c_str());
    Vector2D vecB = Vector2D(x, y);

    //On récupère la couleur
    string color = split[2];

    return new Segment(vecA, vecB, color);
}
