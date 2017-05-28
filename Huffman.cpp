#include "Huffman.h"

Huffman::Huffman(string file){
	inFile.open(file.c_str());
	inFile_read.open(file.c_str());
	outFile.open("outFile.txt");

	alfabeto = new vector<Node*>;
	dicionario = new vector<Node*>;
	tree = new Bt();
	for (int i = 0; i < 256; i++){
		alfabeto->push_back(new Node(0));
		(*alfabeto)[i]->setC(i);
	}
}

Huffman::~Huffman(){
	inFile.close();
	outFile.close();
}

void Huffman::probability(){
	char c;
	while(inFile.get(c)){
		(*alfabeto)[c]->setProb((*alfabeto)[c]->getProb() + 1);
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
	compressTexto();
}

void Huffman::compressTexto(){
	char c;
	int i;
	while (inFile_read.get(c)){
		for (i = 0; (*dicionario)[i]->getC() != c; i++);
		outFile.write((*dicionario)[i]->getCod().c_str(), (*dicionario)[i]->getCod().size());
	}
	// outFile.close();
}