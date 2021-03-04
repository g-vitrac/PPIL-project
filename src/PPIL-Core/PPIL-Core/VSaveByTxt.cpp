#include "VSaveByTxt.h"

void VSaveByTxt::open(const string& file)
{
	if (file.substr(file.find_last_of('.')) != ".txt") throw Error("open : file isn't .txt");
	_fs.open(file); //Clear après chaque ouverture
}

void VSaveByTxt::close()
{
	if (_fs.is_open()) _fs.close();
}

void VSaveByTxt::save(const Circle* circle)
{
	_fs << "Circle|" + circle->getCenter().serialize() + "|" + to_string(circle->getRadius()) + "|" + circle->getColor().getCode() + "\n";
}

void VSaveByTxt::save(const Segment* segment)
{
	_fs << "Segment|" + segment->getVecA().serialize() + "|" + segment->getVecB().serialize() + "|" + segment->getColor().getCode() + "\n";
}

void VSaveByTxt::save(const Polygon* polygon)
{
}

void VSaveByTxt::save(const GroupForm* groupForm)
{
	_fs << "GroupForm|" + groupForm->getColor().getCode() + "\n";
	for (int i = 0; i < groupForm->getChildsFormSize(); i++) {
		groupForm->getChild(i)->save(this);
	}
	_fs << "endGroupForm\n";
}
