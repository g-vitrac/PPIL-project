#pragma once
#include "VRead.h"

class VReadByTxt : public VRead
{
public:
	virtual vector<Form*> read(const string& file);
	Form* parse(string line);
};

inline string parseParameter(string& line, const string& delimiter) {
	size_t pos = line.find(delimiter);
	string result = line.substr(0, pos);
	line.erase(0, pos + string(delimiter).length());
    return result;
}

inline vector<string> parseParameters(string& line, const string& delimiter) {
    vector<string> parameters;
    while ((line.find(delimiter)) != string::npos) {
        parameters.push_back(parseParameter(line, delimiter));
    }
    parameters.push_back(line);
    return parameters;
}

inline Vector2D parseVector(string parameter, const string& delimiter) {
    double x = atof(parameter.substr(0, parameter.find(",")).c_str());
    double y = atof(parameter.substr(parameter.find_last_of(',') + 1).c_str());
    return Vector2D(x, y);
}

inline vector<Vector2D> parseVectors(vector<string> parameters, const string& delimiter, int begin, int end) {
    vector<Vector2D> vectors;
    for (int i = begin; i < end; i++) {
        vectors.push_back(parseVector(parameters[i], delimiter));
    }
    return vectors;
}