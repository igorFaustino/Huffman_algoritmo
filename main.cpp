#include <iostream>
#include "Huffman.h"

using namespace std;

bool compare(Node* a, Node* b){
	return a->getProb() < b->getProb();
}

int main(int argc, char const *argv[])
{
	if (argc != 3){
		cout << "uso: huffman.exe parametro arquivo.txt" << endl;
	}
	Huffman* Huff = new Huffman(argv[1]);
	Huff->compress();
	delete Huff;
	return 0;
}