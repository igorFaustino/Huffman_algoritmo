#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int prob,char c){
	{
		left  = NULL;
		right = NULL;
		word = c;
		probability = prob;
	}	
}

Node::~Node(){
	//dtor
}

char Node::getC(){
	return word;
}

int Node::getProb(){
	return probability;
}

void