#include "Bt.h"


Bt::Bt(){
	root = NULL;
}

void Bt::insert(vector<Node*>* v){
	Node* n1;
	Node* n2;
	Node* x;
	while (v->size() > 1){
		sort(v->begin(), v->end(), compare);
		n1 = (*v)[0];
		n2 = (*v)[1];
		v->erase(v->begin(), v->begin()+1);
		x = new Node(n1->getProb() + n2->getProb());
		x->setLeft(n1);
		x->setRight(n2);
		v->push_back(x);
	}
	root = (*v)[0];
};

void Bt::setCod(Node *node, string cod){
    if(!node->getLeft() && node->getRight()){
    	node->setCod(cod);
    	return;
    }
    if (node->getLeft()){
        setCod(node->getLeft(), cod + "0");
    }
    if (node->getRight()){
        setCod(node->getRight(), cod + "1");
    }
}

void Bt::setCod(){
	if (root->getLeft()){
        setCod(root, "0");
    }
    if (root->getRight()){
        setCod(root, "1");
    }
}

bool Bt::compare(Node* a, Node* b){
		return a->getProb() < b->getProb();
}


void Bt::catchLeaf(Node *node, vector<Node*>* a){
	if (!node){
		return;
	}
	if(!node->getLeft() && !node->getRight()){
		a->push_back(node);
	}
	catchLeaf(node->getLeft(), a);
	catchLeaf(node->getRight(), a);
}

void Bt::catchLeaf(vector<Node*>* a){
	catchLeaf(root, a);
}