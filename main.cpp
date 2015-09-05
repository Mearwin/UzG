#include <iostream>
#include <string>

#include "include/Labyrinthe.h"
#include "include/ListeNoeud.h"

using namespace std;

int main(int nbargs, char** args)
{
    //string path = "/home/thomas/Bureau/lab2.txt";
    string path = args[1];
    char algo = args[2][0];
    Labyrinthe l1(path);

	
    l1.read(path);

    Noeud* ns;
    if (algo =='d') {
        ns = l1.dijkstra();
    } else if (algo == 'a') {
        ns = l1.a_Star();
    }

    l1.tracer_Backtrack(ns);
    l1.afficher();

	
	

    /*Noeud* n = l1.dijkstra();
    Noeud n2(4,9,'A', 0);
    char nature = n.nature;
    cout << n->x << endl;
    cout << n->y << endl;
    cout << n->is_Noeud(n2) << endl;
    */

    /*// Test peek
    ListeNoeud l;
    Noeud* n = new Noeud(1,1,'A',3);
    l.ajout(n);
    n = new Noeud(1,2,'B',2);
    l.ajout(n);
    n = new Noeud(1,3,'C',2);
    l.ajout(n);
    n = new Noeud(1,4,'D',3);
    l.ajout(n);
    n = new Noeud(1,5,'E',4);
    l.ajout(n);
    //cout << l.is_Present(*n) << endl;
    l.display();
    n = l.peek();
    cout << endl << "supp" << endl << endl;
    l.display();
    cout << (char) n->nature << endl;
    */

    /* Test is_Empty
    ListeNoeud l;
    cout << l.is_Empty() << endl;
    Noeud* n = new Noeud(1,1,'A',2);
    l.ajout(n);
    cout << l.is_Empty() << endl;
    l.peek();
    cout << l.is_Empty() << endl;
    */

    /* Test ajout_Si
        ListeNoeud l;
    Noeud* n = new Noeud(1,1,'A',2);
    l.ajout(n);
    n = new Noeud(1,2,'B',2);
    l.ajout(n);
    n = new Noeud(1,3,'C',0);
    l.ajout(n);
    n = new Noeud(1,4,'D',3);
    l.ajout(n);
    n = new Noeud(1,5,'E',4);
    l.ajout(n);
    l.display();
    n = new Noeud(1,2,'F',1);
    l.ajout_Si(n);
    l.display();*/

    return 0;
}
