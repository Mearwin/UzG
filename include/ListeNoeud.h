#ifndef LISTENOEUD_H
#define LISTENOEUD_H

#include "../include/Noeud.h"
#include "../include/Node.h"

#include <iostream>

class ListeNoeud
{
    public:
        ListeNoeud();

        bool is_Present(Noeud nr);
        void ajout(Noeud* na);
        void ajout_Si(Noeud* na);
        void ajout_SiH(Noeud* na);
        void supprimer(Node* ns);
        Noeud* peek();
        Noeud* peekH();
        bool is_Empty();
        void display();

        virtual ~ListeNoeud();
    protected:
    private:
         Node* last_Node;
};

#endif // LISTENOEUD_H
