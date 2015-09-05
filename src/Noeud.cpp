#include "../include/Noeud.h"
#include <iostream>
#include <math.h>

Noeud::Noeud(int x, int y, char nature, double l, double cout_H) : x (x), y (y), nature (nature), l (l), cout_H (cout_H)
{ predecesseur = NULL; }
Noeud::Noeud(int x, int y, char nature, double l) : x (x), y (y), nature (nature), l (l)
{ predecesseur = NULL; }
Noeud::Noeud()
{ predecesseur = NULL; }

Noeud::~Noeud()
{
    //dtor
}


bool Noeud::is_Noeud(Noeud n) {
    return (this->x == n.x && this->y == n.y);
}

double Noeud::distance(Noeud* n) {
    return sqrt(pow(this->x - n->x , 2) + pow(this->y - n->y, 2));
}
