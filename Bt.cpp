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

vector<node*> Bt::catchLeaf(Node *node,vector<node*> *a){
   if(node!=NULL){
    	if(node->getleft()==NULL && node->getRight()=NULL){
    		a->push_back(node);
    			return *a;
    	}
     
     catchLeaf(node->getLeft(),*a);
     catchLeaf(node->getRight(),*a);
 	}
}


void Bt::walk(){
	walk(root);
}