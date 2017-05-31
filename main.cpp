#include <iostream>
#include "Huffman.h"

using namespace std;

bool compare(Node* a, Node* b){
	return a->getProb() < b->getProb();
}

int main(int argc, char const *argv[])
{
	if (argc != 4){
		cout << "uso: huffman.exe -parametro arquivoEntrada.txt arquivoSaida.txt" << endl;
		return 0;
	}
	Huffman* huff = new Huffman(argv[2], argv[3]);
	if (string(argv[1]) == "-c"){
		huff->compress();
	} else if (string(argv[1]) == "-u"){
		huff->uncompress();
	} else {
		cout << "uso: huffman.exe -parametro arquivoEntrada.txt arquivoSaida.txt" << endl;
	}
	delete huff;
	return 0;
}