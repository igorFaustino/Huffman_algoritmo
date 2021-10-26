#include <iostream>
#include "Huffman.h"

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		cout << "uso: huffman.exe -parametro arquivo.txt" << endl;
		return 0;
	}
	Huffman *huff = new Huffman(argv[2], argv[1]);
	if (string(argv[1]) == "-c")
	{
		huff->compress();
	}
	else if (string(argv[1]) == "-d")
	{
		huff->uncompress();
	}
	else
	{
		cout << "uso: huffman.exe -parametro arquivo.txt" << endl;
	}
	delete huff;
	return 0;
}
