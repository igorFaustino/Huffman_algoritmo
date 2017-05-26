#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int prob,char c){
	{
		left  = NULL;
		right = NULL;
		this->c = c;
		this->prob = prob;
		this->cod = -1;
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
	this->c = c;
}

void Node::setProb(int prob){
	this->prob = prob;
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

void Node::print(){
	cout << "Prob: " << this->prob << endl;
	cout << "c: " << this->c << endl;
}

int Node::getCod(){
	return cod;
}

void Node::setCod(int value){
	this->cod = value;
}
