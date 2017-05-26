#include "Bt.h"

Bt::Bt(){
	root = NULL;
}

void Bt::insert(list<Node*>* nodeList){
	nodeList->sort();
};

void Bt::walk(Node *node){
    if (node!=NULL){
        walk(node->getLeft());
        walk(node->getRight());
    }
}

void Bt::walk(){
	walk(root);
}