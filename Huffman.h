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
	Huffman(string file);
	~Huffman();
	void compress();
	void uncompress();

private:
	void makeDictionary();
	void makeTree();
	void probability();
	void saveDictionary();
	void compressTexto();
	ifstream inFile;
	ifstream inFile_read;
	ofstream outFile;
	vector<Node*>* alfabeto;
	vector<Node*>* dicionario;
	Bt* tree;
	
};

#endif