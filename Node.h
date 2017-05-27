#ifndef NODE
#define NODE 
#include <iostream>

using namespace std;

class Node
{
public:
	Node(int prob);
	virtual ~Node();
	char getC();
	int getProb();
	void setC(char c);
	void setProb(int prob);
	Node* getLeft();
   	Node* getRight();
   	void setRight(Node*);
    void setLeft(Node*);
	bool compare(const Node* first, const Node* second);
	void print();
	string getCod();
	void setCod(string value);

	
private:
	char c;
	int prob;
	string cod;

	Node* left;
	Node* right;
};

#endif
