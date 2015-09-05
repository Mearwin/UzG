#include "../include/ListeNoeud.h"
#include "../include/Node.h"

using namespace std;

ListeNoeud::ListeNoeud()
{
    last_Node = NULL;
}

bool ListeNoeud::is_Present(Noeud nr) {

    Node* ni = this->last_Node;

    while (ni != NULL) {
        if (ni->getNoeud()->is_Noeud(nr)) {
            return true;
        }
        ni = ni->getPred();
    }
    return false;

}

void ListeNoeud::ajout(Noeud* na) {
    Node* nNode = new Node(na);
    if (last_Node != NULL) {
        last_Node->setSucc(nNode);
        nNode->setPred(last_Node);
    }
    last_Node = nNode;
}

void ListeNoeud::ajout_Si(Noeud* na) {
    Node* ni = this->last_Node;
    bool trouvee = false;

    while (ni != NULL) {
        if (ni->getNoeud()->is_Noeud(*na)) {
            if (ni->getNoeud()->l > na->l) {
                supprimer(ni);
                ajout(na);
            }
            trouvee = true;
        }
        ni = ni->getPred();
    }
    if (!trouvee) {
        ajout(na);
    }
}

void ListeNoeud::ajout_SiH(Noeud* na) {
    Node* ni = this->last_Node;
    bool trouvee = false;

    while (ni != NULL) {
        if (ni->getNoeud()->is_Noeud(*na)) {
            if (ni->getNoeud()->cout_H > na->cout_H) {
                supprimer(ni);
                ajout(na);
            }
            trouvee = true;
        }
        ni = ni->getPred();
    }
    if (!trouvee) {
        ajout(na);
    }
}

void ListeNoeud::supprimer(Node* ns) {
    if (ns->getPred() != NULL) {
    ns->getPred()->setSucc(ns->getSucc());
    }
    if (ns->getSucc() != NULL) {
    ns->getSucc()->setPred(ns->getPred());
    } else {
        last_Node = ns->getPred();
    }
}

Noeud* ListeNoeud::peek() {
    Noeud* retour = NULL;
    Node* ni = this->last_Node;

    double cout_Min = ni->getNoeud()->l;

    while (ni != NULL) {
        if ((ni->getNoeud()->l) <= cout_Min) {
            if (retour != NULL) {
                this->ajout(retour);
            }
            retour = ni->getNoeud();
            cout_Min = retour->l;
            supprimer(ni);
        }
        ni = ni->getPred();
    }
    return retour;
}

Noeud* ListeNoeud::peekH() {
    Noeud* retour = NULL;
    Node* ni = this->last_Node;

    double cout_Min = ni->getNoeud()->cout_H;

    while (ni != NULL) {
        if ((ni->getNoeud()->cout_H) <= cout_Min) {
            if (retour != NULL) {
                this->ajout(retour);
            }
            retour = ni->getNoeud();
            cout_Min = retour->cout_H;
            supprimer(ni);
        }
        ni = ni->getPred();
    }
    return retour;
}

bool ListeNoeud::is_Empty() {
return (last_Node == NULL);
}

void ListeNoeud::display() {

    Node* ni = this->last_Node;
    while (ni != NULL) {
        cout << ni->getNoeud()->x << "-" << ni->getNoeud()->y << "-" <<(char) ni->getNoeud()->nature << endl;
        ni = ni->getPred();
    }

}

ListeNoeud::~ListeNoeud()
{
}
