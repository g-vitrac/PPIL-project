#include "TxtCircle.h"

Form* TxtCircle::detected(string line) const
{
    size_t pos = 0;

    //On récupère le nom de classe
    pos = line.find("|");
    if (line.substr(0, pos) != "Circle") return NULL;
    line.erase(0, pos + string("|").length());

    vector<string> split;
    while ((pos = line.find("|")) != std::string::npos) {
        split.push_back(line.substr(0, pos));
        line.erase(0, pos + string("|").length());
    }
    split.push_back(line);

    //On récupère le centre
    double centerX = atof(split[0].substr(0, split[0].find(",")).c_str());
    double centerY = atof(split[0].substr(split[0].find_last_of(',') + 1).c_str());
    Vector2D center = Vector2D(centerX, centerY);

    //On récupère le rayon
    double radius = atof(split[1].c_str());

    //On récupère la couleur
    string color = split[2];

    return new Circle(center, radius, color);
}
