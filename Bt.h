#ifndef TREE
#define TREE 

#include "Node.h"
#include <list>

using namespace std;

class Bt
{
public:
	Bt();
	~Bt();

	void insert(list<Node>* list);
private:
	Node* root;
};
#endif