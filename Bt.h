#ifndef TREE
#define TREE 

#include "Node.h"
#include <list>
#include <iostream>
#include <vector> 
#include <algorithm> // sort()

using namespace std;

class Bt
{
public:
	Bt();
	~Bt();

	void insert(vector<Node*>* v);
	void setCod();
	void catchLeaf(vector<Node*>* a);
private:
	Node* root;
	void setCod(Node* node, string cod);
	void catchLeaf(Node *node,vector<Node*>* a);
	static bool compare(Node* a, Node* b);
};

#endif
