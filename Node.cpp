#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int prob,char c){
	{
		left  = NULL;
		right = NULL;
		this->c = c;
		this->prob = prob;
	}	
}

Node::~Node(){
	//dtor
}

char Node::getC(){
	return c;
}

int Node::getProb(){
	return prob;
}

void Node::setC(char c){
	c = c;
}

void Node::setProb(int prob){
	prob = prob;
}

void Node::setData(int d)
{
    data = d;
}

Node* Node::getLeft()
{
    return left;
}

Node* Node::getRight()
{
    return right;
}

void Node::setRight(Node *node)
{
    right = node;
}

void Node::setLeft(Node *node)
{
    left = node;
}
