#include "Huffman.h"

Huffman::Huffman(string file){
	inFile.open(file.c_str());
	outFile.open("outFile.txt");

	alfabeto = new vector<Node*>;
	dicionario = new vector<Node*>;
	tree = new Bt();
	cout << "estou aqui!" << endl;
	for (int i = 0; i < 256; i++){
		// cout << i << " ";
		alfabeto->push_back(new Node(0));
		(*alfabeto)[i]->setC(i);
		cout << alfabeto->back()->getC() << ' ';
	}
	cout << "complete";
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
	for (int i = 0; i < dicionario->size(); i++){
		(*dicionario)[i]->print();
	}
}