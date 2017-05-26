#ifndef TREE
#define TREE 

#include "Node.h"
#include <list>
#include <iostream>

using namespace std;

class Bt
{
public:
	Bt();
	~Bt();

	void insert(list<Node*>* nodeList);
	bool compare(const Node* a, const Node* b);
private:
	Node* root;
};

#endif