#include "Bt.h"

Bt::Bt(){
	root = NULL;
}

void Bt::insert(list<Node*>* nodeList){
	nodeList->sort();
};

void Bt::walk(Node *node){
    if (node->getLeft()){
        walk(node->getLeft());
    }
    if (node->getRight()){
        walk(node->getRight());
    }
}

void Bt::walk(){
	walk(root);
}