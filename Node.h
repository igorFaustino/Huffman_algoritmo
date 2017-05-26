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
	
private:
	char c;
	int prob;
};

#endif