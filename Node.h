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
	int getCod();
	void setCod(int value);

	
private:
	char c;
	int prob;
	int cod;

	Node* left;
	Node* right;
};

#endif
