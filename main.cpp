#include <iostream>
#include <vector>
#include "Node.h"
#include <algorithm>    // sort()

using namespace std;

bool compare(Node* a, Node* b){
	return a->getProb() < b->getProb();
}

int main(int argc, char const *argv[])
{
	Node* n1 = new Node(5);
	Node* n2 = new Node(3);
	Node* n3 = new Node(2);
	vector<Node*> l;
	l.push_back(n1);
	l.push_back(n2);
	l.push_back(n3);
	cout << "Primeiro cara: " << l.front()->getProb() << endl;
	sort(l.begin(), l.end(), compare);
	cout << "Primeiro cara ordenado: " << l.front()->getProb() << endl;
	for (int i = 0; i < 3; i++){
		l[i]->print();
	}

	return 0;
}