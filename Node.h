#ifndef NODE
#define NODE 

using namespace std;

class Node
{
public:
	Node(int prob, char c);
	~Node();
	char getC();
	int getProb();
	void setC(char c);
	void setProb(int prob);
	bool compare(Node* first, Node* second);
	
private:
	char c;
	int prob;
};

#endif