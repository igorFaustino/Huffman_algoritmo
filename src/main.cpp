#include <iostream>
#include "Huffman.h"

using namespace std;

const string HOW_TO_USE = "how to use: huff -param in.txt";

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		cout << HOW_TO_USE << endl;
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
		cout << HOW_TO_USE << endl;
	}
	delete huff;
	return 0;
}
