#include "../include/Labyrinthe.h"
#include "../include/Noeud.h"
#include "../include/ListeNoeud.h"
#include "../include/InterfaceGraphique.h"

#include <iostream>
#include <fstream>
#include <malloc.h>


using namespace std;

Labyrinthe::Labyrinthe(int l, int h)
{
    largeur = l;
    largeur_Reel = l+1;
    hauteur = h;
    data = (char**) malloc(sizeof(char*)*(hauteur));
	for (int i = 0; i<(hauteur); i++) {
		data[i] = (char*) malloc(sizeof(char)*largeur_Reel);
	}
}

Labyrinthe::Labyrinthe(string& path) {
    // Lecture du fichier
    bool success = true;
    char c;
    int col = 0;
    int ligne = 0;

    textFile.open(path.c_str());

    if (textFile.is_open()) {
        while (c != 10) {
            col++;
            textFile.get(c);
        }
        largeur = col-1;
        while (!textFile.eof()) {
            if (c == 10) {
                ligne++;
            }
            textFile.get(c);
        }
        hauteur = ligne;
    } else {
        cout << "Echec de l'ouverture du fichier." << endl;
        success = false;
    }
    cout << "Hauteur: " << hauteur << " Largeur: " << largeur << endl;
    textFile.close();

    largeur_Reel = largeur+1;
    // Creation de data
    data = (char**) malloc(sizeof(char*)*(hauteur));
	for (int i = 0; i<(hauteur); i++) {
		data[i] = (char*) malloc(sizeof(char)*largeur_Reel);
	}
}

bool Labyrinthe::read(string& path) {
    bool success = true;
    textFile.open(path.c_str());

    if (textFile.is_open()) {
        for (int i = 0;  i < hauteur; i++) {
            for (int j = 0; j < largeur_Reel; j++) {
                textFile.get(data[i][j]);
            }
        }
        textFile.close();
    } else {
        success = false;
    }
    return success;
}

void Labyrinthe::display() {
    char c;
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur_Reel; j++) {
            c = data[i][j];
            if (c == 'D' || c == 'A') {
                cout << "\033[32m" << c << "\033[00m";
            } else if (c == 'P') {
                cout << "\033[31m" << c << "\033[00m";
            } else if (c == '1') {
                cout << "\033[34m" << c << "\033[00m";
            } else if (c == 'E') {
                cout << "\033[33m" << c << "\033[00m";
            } else {
                cout << data[i][j];
            }
        }
    }
}
	
 void Labyrinthe::afficher() {

	InterfaceGraphique* ig =  new InterfaceGraphique(largeur, hauteur);
    char c;
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur_Reel; j++) {
            if (data[i][j] == 'D' || data[i][j] == 'A') {
               	ig->set_Square(i, j, 1);
            } else if (data[i][j] == 'P') {
                ig->set_Square(i, j, 2);
            } else if (data[i][j] == '1') {
               	ig->set_Square(i, j, 3);
           } else if (data[i][j] == 'E') {
                ig->set_Square(i, j, 4);
            } else { 
				ig->set_Square(i, j, 5);                          } 
        }
    }
	getchar();
	ig->~InterfaceGraphique();
 }

Noeud* Labyrinthe::dijkstra() {
    ListeNoeud lo;
    ListeNoeud lf;
    Noeud* nd = NULL;
    // Initialisation premier noeud.
    for (int ligne = 0; ligne < hauteur; ligne++) {
        for (int col = 0; col < largeur; col++) {
            if (data[ligne][col] == 'D') {
                nd = new Noeud(col, ligne, 'D', 0);
                //cout << "TROUVEE" << endl;
            }
        }
    }

    lo.ajout(nd);

    Noeud* nc = NULL;
    Noeud* nc2 = NULL;
    int x, y, conteur = 0;
    //Boulce principale
    do {
        conteur++;

        nc = lo.peek();
        lf.ajout(nc);

        if (data[nc->y][nc->x] != 'A' && data[nc->y][nc->x] != 'D') {
            data[nc->y][nc->x] = 'E';
        }

        x = nc->x -1;
        y = nc->y;

	        if (x >= 0) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_Si(nc2);
                }
                //data[y][x] = 'E';
            }
        }
        x = nc->x +1;
        if (x < largeur) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_Si(nc2);
                }
                //data[y][x] = 'E';
            }
        }
        x = nc->x;
        y = nc->y -1;
        if (y >= 0) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_Si(nc2);
                }
                //data[y][x] = 'E';
            }
        }
        y = nc->y +1;
        if (y < hauteur) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_Si(nc2);
                }
                //data[y][x] = 'E';
            }
        }
    } while (nc->nature != 'A' && conteur < 10000);
    cout << "nb case exploree:" << conteur << endl;
    return nc;
}

Noeud* Labyrinthe::a_Star() {
    ListeNoeud lo;
    ListeNoeud lf;
    Noeud* nd = NULL;
    Noeud* na = NULL;
    // Initialisation premier noeud.
    for (int ligne = 0; ligne < hauteur; ligne++) {
        for (int col = 0; col < largeur; col++) {
            if (data[ligne][col] == 'D') {
                nd = new Noeud(col, ligne, 'D', 0);
                //cout << "TROUVEE" << endl;
            }
        }
    }

    //Recherche arrivée.
    for (int ligne = 0; ligne < hauteur; ligne++) {
        for (int col = 0; col < largeur; col++) {
            if (data[ligne][col] == 'A') {
                na = new Noeud(col, ligne, 'A', 0);
                //cout << "TROUVEE" << endl;
            }
        }
    }

    lo.ajout(nd);

    Noeud* nc = NULL;
    Noeud* nc2 = NULL;
    int x, y, conteur = 0;
    //Boulce principale
    do {
        conteur++;

        nc = lo.peekH();
        lf.ajout(nc);

        if (data[nc->y][nc->x] != 'A' && data[nc->y][nc->x] != 'D') {
            data[nc->y][nc->x] = 'E';
        }

        x = nc->x -1;
        y = nc->y;

        if (x >= 0) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                nc2->cout_H = nc2->l + nc2->distance(na);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_SiH(nc2);
                }
                //data[y][x] = 'E';
            }
        }
        x = nc->x +1;
        if (x < largeur) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                nc2->cout_H = nc2->l + nc2->distance(na);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_SiH(nc2);
                }
                //data[y][x] = 'E';
            }
        }
        x = nc->x;
        y = nc->y -1;
        if (y >= 0) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                nc2->cout_H = nc2->l + nc2->distance(na);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_SiH(nc2);
                }
                //data[y][x] = 'E';
            }
        }
        y = nc->y +1;
        if (y < hauteur) {
            if (data[y][x] != '1') {
                nc2 = new Noeud(x, y, data[y][x], nc->l+1);
                nc2->cout_H = nc2->l + nc2->distance(na);
                if (!(lf.is_Present(*nc2))) {
                    nc2->predecesseur = nc;
                    lo.ajout_SiH(nc2);
                }
                //data[y][x] = 'E';
            }
        }
    } while (nc->nature != 'A' && conteur < 10000);
    cout << "nb case exploree:" << conteur << endl;
    return nc;
}

void Labyrinthe::tracer_Backtrack(Noeud* n) {
    Noeud* ni = n;
    int conteur = 0;

    while (ni->predecesseur != NULL) {
        conteur++;
        if (data[ni->y][ni->x] != 'A' && data[ni->y][ni->x] != 'D') {
            data[ni->y][ni->x] = 'P';
        }
        ni = ni->predecesseur;
    }
    cout << "nb pas:" << conteur << endl;
}

Labyrinthe::~Labyrinthe()
{
    //dtor
}
