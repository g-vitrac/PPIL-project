#include "TxtGroupForm.h"
#include "VReadByTxt.h"

Form* TxtGroupForm::detected(string line) const
{
    size_t pos = 0;

    //On récupère le nom de classe
    pos = line.find("|");
    if (line.substr(0, pos) != "GroupForm") return NULL;
    line.erase(0, pos + string("|").length());

    //On récupère la couleur
    string color = line;

    VReadByTxt* visitorDrawText = new VReadByTxt();
    GroupForm* result = new GroupForm(color);
    Form* childResult;

    getline(VRead::_fs, line);
    while (line != "endGroupForm") {
        childResult = visitorDrawText->parse(line);
        if (childResult) result->insertChild(childResult);
        if (!getline(VRead::_fs, line)) throw Error("detected : file is corrupt");
    } 
    return result;
}
