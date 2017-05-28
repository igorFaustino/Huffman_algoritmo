#include <iostream>
#include "Huffman.h"

using namespace std;

bool compare(Node* a, Node* b){
	return a->getProb() < b->getProb();
}

int main(int argc, char const *argv[])
{

	Huffman* Huff = new Huffman(argv[1]);
	Huff->compress();

	return 0;
}