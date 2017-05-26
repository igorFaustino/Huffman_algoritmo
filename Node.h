#ifndef NODE
#define NODE 

using namespace std;

class Node
{
public:
	Node(int prob, char c);
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
	bool operator()(Node const * lhs, Node const * rhs) {return lhs->prob < rhs->prob;};

	
private:
	char c;
	int prob;

	Node* left;
	Node* right;
};

#endif
