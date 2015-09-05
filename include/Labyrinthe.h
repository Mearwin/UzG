#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include "Noeud.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Labyrinthe
{
    public:
        Labyrinthe(int l, int h);
        Labyrinthe(string& path);

        int largeur;
        int hauteur;

        ifstream textFile;
        bool read(string& path);
        void display();
		void afficher();

        Noeud* dijkstra();
        Noeud* a_Star();
        void tracer_Backtrack(Noeud* n);

        virtual ~Labyrinthe();
    protected:
    private:
        char** data;
        int largeur_Reel;
};

#endif // LABYRINTHE_H
