#include "Huffman.h"

Huffman::Huffman(char* file){
	inFile.open(file);
	outFile.open("outFile.txt");

	for (int i = 0; i < 256; i++){
		alfabeto.push_back(new Node(0));
		alfabeto.back()->setC(i);
	}
}

void Huffman::probability(){
	char c;
	while(inFile.get(c)){
		alfabeto[c]++;
	}
	int i = 0;
	while(i < alfabeto.size()){
		if (alfabeto[i]->getProb() != 0)
			i++;
		else {
			alfabeto.erase(alfabeto.begin()+i);
		}
	}
}