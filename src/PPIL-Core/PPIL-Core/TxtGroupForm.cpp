#include "TxtGroupForm.h"
#include "VReadByTxt.h"

Form* TxtGroupForm::detected(string line) const
{
    //On récupère le nom de classe
    string delimiter = "|";
    if (parseParameter(line, delimiter) != "GroupForm") return NULL;

    //On récupère la couleur
    string color = parseParameter(line, delimiter);

    VReadByTxt* visitorDrawText = new VReadByTxt();
    GroupForm* result = new GroupForm(color);
    Form* childResult;

    getline(VRead::_fs, line);
    while (line != "endGroupForm") {
        childResult = visitorDrawText->parse(line);
        if (childResult) result->insertChild(childResult);
        if (!getline(VRead::_fs, line)) throw Error("detected : file is corrupt");
    } 
    delete visitorDrawText;
    return result;
}
