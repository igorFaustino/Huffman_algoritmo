#ifndef HUFFMAN
#define HUFFMAN 
#include <vector>
#include <iostream>
#include "Node.h"
#include "Huffman.h"
#include "Bt.h"
#include <fstream>
#include <stdio.h>
#include <string>


class Huffman
{
public:
	Huffman(string in, string out);
	~Huffman();
	void compress();
	void uncompress();

private:
	void makeDictionary();
	void dictionaryFromFile();
	void makeTree();
	void probability();
	void saveDictionary();
	void compressTexto();
	void uncompressTexto();
	bool testFile();
	
	ifstream inFile;
	ifstream inFile_read;
	ofstream outFile;
	vector<Node*>* alfabeto;
	vector<Node*>* dicionario;
	Bt* tree;
	string text;
	
};

#endif