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

private:
	ifstream inFile;
	ofstream outFile;
	vector<Node*> alfabeto;
	
};

#endif