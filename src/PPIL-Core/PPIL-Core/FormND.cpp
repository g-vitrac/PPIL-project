#include "FormND.h"

Marking* FormND::getAnchorMarking() const
{
    return _anchorMarking;
}

Marking* FormND::getGravityMarking() const
{
    return _gravityMarking;
}

Marking* FormND::calculateGravityMarking(vector<Point*> collection)
{
    int size = collection.size();
    if (size > 0) {
        double posX = 0;
        double posY = 0;
        for (int i = 0; i < size; i++) {
            posX += collection[i]->getPosX();
            posY += collection[i]->getPosY();
        }
        return new Marking(new Point(_color, posX / size, posY / size));
    }
    else {
        throw new Erreur("calculateGravityMarking : collection taille <= 0");
    }

    return NULL;
}

ostream& FormND::afficher(ostream& o) const
{
    o << "FormND (";
    Form::afficher(o);
    return o << "\n      gravity marking = " << *_gravityMarking << ")";
}
