#include "Huffman.h"

Huffman::Huffman(char* file){
	inFile.open(file);
	outFile.open("outFile.txt");

	alfabeto = new vector<Node*>;
	dicionario = new vector<Node*>;
	tree = new Bt();

	for (int i = 0; i < 256; i++){
		alfabeto->push_back(new Node(0));
		alfabeto->back()->setC(i);
	}
}

Huffman::~Huffman(){
	inFile.close();
	outFile.close();
}

void Huffman::probability(){
	char c;
	while(inFile.get(c)){
		(*alfabeto)[c]++;
	}
	int i = 0;
	while(i < alfabeto->size()){
		if ((*alfabeto)[i]->getProb() != 0)
			i++;
		else {
			alfabeto->erase(alfabeto->begin()+i);
		}
	}
}

void Huffman::makeTree(){
	tree->insert(alfabeto);
	tree->setCod();
}

void Huffman::makeDicionario(){
	tree->catchLeaf(dicionario);
}

void Huffman::compress(){
	probability();
	makeTree();
	makeDicionario();
}