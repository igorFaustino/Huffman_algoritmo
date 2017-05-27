#ifndef HUFFMAN
#define HUFFMAN 
#include <vector>
#include <iostream>
#include "Node.h"
#include "Huffman.h"
#include "Bt.h"
#include <fstream>


class Huffman
{
public:
	Huffman(char* file);
	~Huffman();
	void probability();
	void makeTree();
	void makeDicionario();
	void compress();
	void uncompress();

private:
	ifstream inFile;
	ofstream outFile;
	vector<Node*>* alfabeto;
	vector<Node*>* dicionario;
	Bt* tree;
	
};

#endif