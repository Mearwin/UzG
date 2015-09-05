#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "../include/Noeud.h"

class Node
{
    public:
        Node(Noeud* nn);

        Noeud* getNoeud();
        Node* getPred();
        Node* getSucc();
        void setNoeud(Noeud* n);
        void setPred(Node* n);
        void setSucc(Node* n);

        virtual ~Node();
    protected:
    private:
        Noeud* n;
        Node* pred;
        Node* succ;
};

#endif // NODE_H
