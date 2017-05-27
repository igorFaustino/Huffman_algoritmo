#ifndef TREE
#define TREE 

#include "Node.h"
#include <list>
#include <iostream>
#include <vector>

using namespace std;

class Bt
{
public:
	Bt();
	~Bt();

	void insert(list<Node*>* nodeList);
	bool compare(const Node* a, const Node* b);
	void walk();
	vector<node*> catchLeaf(Node *node,vector<node*> *a){
private:
	Node* root;
	void walk(Node* node);

};

#endif