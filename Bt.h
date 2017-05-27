#ifndef TREE
#define TREE 

#include "Node.h"
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Bt
{
public:
	Bt();
	~Bt();

	void insert(vector<Node*> v);
	void setCod();
private:
	Node* root;
	void setCod(Node* node, string cod);

	static bool compare(Node* a, Node* b);
};

#endif