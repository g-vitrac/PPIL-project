#include "VSaveByTxt.h"

void VSaveByTxt::open(const string& file)
{
	try {
		if (file.substr(file.find_last_of('.')) != ".txt") throw Error("open : file isn't .txt");
		//_fs.open(file, ios::out | ios::app);
		_fs.open(file); //Clear après chaque ouverture
	}
	catch (Error const& err) {
		throw err;
	}
}

void VSaveByTxt::close()
{
	try {
		if (_fs.is_open()) _fs.close();
	}
	catch (Error const& err) {
		throw err;
	}
}

void VSaveByTxt::save(const Circle* circle)
{
	_fs << "Circle|" + circle->getCenter().serialize() + "|" + to_string(circle->getRadius()) + "|" + circle->getColor() + "\n";
}

void VSaveByTxt::save(const Segment* segment)
{
	_fs << "Segment|" + segment->getVecA().serialize() + "|" + segment->getVecB().serialize() + "|" + segment->getColor() + "\n";
}

void VSaveByTxt::save(const PolygonConvex* polygonConvex)
{
}

void VSaveByTxt::save(const GroupForm* groupForm)
{
	_fs << "GroupForm|" + groupForm->getColor() + "\n";
	for (int i = 0; i < groupForm->getChildsFormSize(); i++) {
		groupForm->getChild(i)->save(this);
	}
	_fs << "endGroupForm\n";
}
