#include "Huffman.h"

using namespace std;

Huffman::Huffman(string in, string parametro){
	if(parametro == "-c"){
		inFile.open(in.c_str());
		inFile_read.open(in.c_str());
		outFile.open("outFile.huf", ios::binary);
	}
	if(parametro == "-d"){
		inFile_read.open(in.c_str());
		inFile.open(in.c_str(), ios::binary);
		outFile.open("outfile.txt");
	}
	alfabeto = new vector<Node*>;
	dicionario = new vector<Data*>;
	tree = new Bt();
	for (int i = 0; i < 256; i++){
		alfabeto->push_back(new Node(0));
		(*alfabeto)[i]->setC(i);
	}
}

Huffman::~Huffman(){
	inFile.close();
	inFile_read.close();
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

void Huffman::makeDictionary(){
	tree->catchLeaf(dicionario);
}

void Huffman::compress(){
	if (testFile()){
		probability();
		makeTree();
		makeDictionary();
		saveDictionary();
		compressTexto();
	} else {
		cout << "uso: huffman.exe -parametro arquivo.txt" << endl;
	}
}	

void Huffman::saveDictionary(){
	int i=0;
	int tam = dicionario->size();
	outFile.write((char*)&(tam), sizeof(tam));
	for(i = 0; i < dicionario->size(); i++){
		outFile.write((char*)&(*(*dicionario)[i]), sizeof((*dicionario)[i]));
	}
}

void Huffman::compressTexto(){
	char c;
	string str = "";
	int i;
	while (inFile_read.get(c)){
		for (i = 0; (*dicionario)[i]->getC() != c && i < dicionario->size(); i++);
		ostringstream convert;
		convert << (*dicionario)[i]->getCod();
		string aux = convert.str();
		str = str + aux;
	}
	unsigned int aux = 0;
	string cod = "";
	binario* bin = new binario();
	int tam = str.size();
	outFile.write((char*)&tam, sizeof(tam));
	for (i = 0; i < str.size(); i++){
		cod = cod + str[i];
		if (cod.size() >= 32){
			aux = bin->converter_int(cod);
			outFile.write((char*)&(aux), sizeof(aux));
			cod = "";
		}
	}
	if (cod.size() != 0){
		aux = bin->converter_int(cod);
		outFile.write((char*)&(aux), sizeof(aux));
	}
}

void Huffman::dictionaryFromFile(){
	int tam;
	inFile.read((char*)&tam, sizeof(tam));
	for(int i = 0; i < tam; i++){
		Data* d = new Data();
		inFile.read((char*)d, sizeof(d));
		dicionario->push_back(d);
	}
}

void Huffman::uncompress(){
	if (testFile()){
		dictionaryFromFile();
		uncompressTexto();
	} else {
		cout << "uso: huffman.exe -parametro arquivo.txt" << endl;
	}
}

bool Huffman::testFile(){
	bool a, b, c;
	a = inFile.is_open();
	b = inFile_read.is_open();
	c = outFile.is_open();
	return a && b && c;
}

int Huffman::textFromBin(){
	int tam;
	binario* b = new binario;
	unsigned int aux;
	text = "";
	string str;
	inFile.read((char*)&tam, sizeof(tam));
	while(inFile.read((char*)&aux, sizeof(aux))){
		str = b->converter_str(aux);
		if (str != "\0")
			text = text + str;
	}
	return tam;
}

void Huffman::uncompressTexto(){
	int tam = textFromBin();
	string str = "";
	for(int i = 0; i < tam; i++){
		int j;
		str = str + text[i];
		for(j = 0; j < dicionario->size() && atoi(str.c_str()) != (*dicionario)[j]->getCod(); j++);
		if (j < dicionario->size()){
			str = (*dicionario)[j]->getC();
			if (str[0] != '\0')
				outFile.put(str[0]);
			str = "";
		}

	}
}