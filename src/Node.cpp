#include "../include/Node.h"

Node::Node(Noeud* nn) : n (nn)
{
    this->succ = NULL;
    this->pred = NULL;
}

Noeud* Node::getNoeud() {
    return this->n;
}

Node* Node::getPred() {
    return this->pred;
}

Node* Node::getSucc() {
    return this->succ;
}

void Node::setNoeud(Noeud* nn) {
    this->n = nn;
}

void Node::setPred(Node* nn) {
    this->pred = nn;
}

void Node::setSucc(Node* nn) {
    this->succ = nn;
}

Node::~Node()
{
}
