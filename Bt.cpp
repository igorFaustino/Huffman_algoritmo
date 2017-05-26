#include "Bt.h"

Bt::Bt(){
	root = NULL;
}

void Bt::insert(list<Node*>* nodeList){
	nodeList->sort();
};
