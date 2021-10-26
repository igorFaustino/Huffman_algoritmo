#include "Huffman.h"

using namespace std;

Huffman::Huffman(string in, string parametro)
{
	if (parametro == "-c")
	{
		inFile.open(in.c_str());
		inFile_read.open(in.c_str());
		outFile.open("outFile.huf", ios::binary);
	}
	if (parametro == "-d")
	{
		inFile_read.open(in.c_str());
		inFile.open(in.c_str(), ios::binary);
		outFile.open("outfile.txt");
	}
	alfabeto = new vector<Node *>;
	dicionario = new vector<Data *>;
	tree = new Bt();
	for (int i = 0; i < 256; i++)
	{
		alfabeto->push_back(new Node(0));
		(*alfabeto)[i]->setC(i);
	}
}

Huffman::~Huffman()
{
	inFile.close();
	inFile_read.close();
	outFile.close();
}

void Huffman::probability()
{
	char c;
	while (inFile.get(c))
	{
		(*alfabeto)[c]->setProb((*alfabeto)[c]->getProb() + 1);
	}
	int i = 0;
	while (i < alfabeto->size())
	{
		if ((*alfabeto)[i]->getProb() != 0)
			i++;
		else
		{
			alfabeto->erase(alfabeto->begin() + i);
		}
	}
}

void Huffman::makeTree()
{
	tree->insert(alfabeto);
	tree->setCod();
}

void Huffman::makeDictionary()
{
	tree->catchLeaf(dicionario);
}

void Huffman::compress()
{
	if (testFile())
	{
		probability();
		makeTree();
		makeDictionary();
		saveDictionary();
		compressTexto();
	}
	else
	{
		cout << "uso: huffman.exe -parametro arquivo.txt" << endl;
	}
}

void Huffman::saveDictionary()
{
	int i = 0;
	int tam = dicionario->size();
	outFile.write((char *)&(tam), sizeof(tam));
	for (i = 0; i < dicionario->size(); i++)
	{
		outFile.put((*dicionario)[i]->getC());
		string str = (*dicionario)[i]->getCod();
		short int len = str.size();
		outFile.write((char *)&len, sizeof(len));
		outFile.write(str.c_str(), len);
	}
}

void Huffman::compressTexto()
{
	char c;
	string str = "";
	int i;
	while (inFile_read.get(c))
	{
		for (i = 0; (*dicionario)[i]->getC() != c && i < dicionario->size(); i++)
			;
		ostringstream convert;
		convert << (*dicionario)[i]->getCod();
		string aux = convert.str();
		str = str + aux;
	}
	unsigned int aux = 0;
	string cod = "";

	int tam = str.size();
	outFile.write((char *)&tam, sizeof(tam));
	for (i = 0; i < str.size(); i++)
	{
		cod = cod + str[i];
		if (cod.size() >= 32)
		{
			aux = BinaryHelper::parse_int(cod);
			outFile.write((char *)&(aux), sizeof(aux));
			cod = "";
		}
	}
	if (cod.size() != 0)
	{
		while (cod.size() != 32)
			cod = cod + "0";
		aux = BinaryHelper::parse_int(cod);
		outFile.write((char *)&(aux), sizeof(aux));
	}
}

void Huffman::dictionaryFromFile()
{
	int tam;
	inFile.read((char *)&tam, sizeof(tam));
	for (int i = 0; i < tam; i++)
	{
		char c;
		string str;
		short int len;
		inFile.get(c);
		inFile.read((char *)&len, sizeof(len));
		char *buf = new char[len];
		inFile.read(buf, len);
		str = "";
		str.append(buf, len);
		dicionario->push_back(new Data(str, c));
	}
}

void Huffman::uncompress()
{
	if (testFile())
	{
		dictionaryFromFile();
		uncompressTexto();
	}
	else
	{
		cout << "uso: huffman.exe -parametro arquivo.txt" << endl;
	}
}

bool Huffman::testFile()
{
	bool a, b, c;
	a = inFile.is_open();
	b = inFile_read.is_open();
	c = outFile.is_open();
	return a && b && c;
}

int Huffman::textFromBin()
{
	int tam;
	unsigned int aux;
	text = "";
	string str;
	inFile.read((char *)&tam, sizeof(tam));
	while (inFile.read((char *)&aux, sizeof(aux)))
	{
		str = BinaryHelper::parse_str(aux);
		if (str != "\0")
			text = text + str;
	}
	return tam;
}

void Huffman::uncompressTexto()
{
	int tam = textFromBin();
	string str = "";
	for (int i = 0; i < tam; i++)
	{
		int j;
		str = str + text[i];
		for (j = 0; j < dicionario->size() && (str.c_str()) != (*dicionario)[j]->getCod(); j++)
			;
		if (j < dicionario->size())
		{
			str = (*dicionario)[j]->getC();
			if (str[0] != '\0')
				outFile.put(str[0]);
			str = "";
		}
	}
}
