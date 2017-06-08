#include "Huffman.h"

using namespace std;

Huffman::Huffman(string in, string parametro){
	if(parametro == "-c"){
		inFile.open(in.c_str());
		inFile_read.open(in.c_str());
		outFile.open("outFile.huf", ios::binary);
	}
	if(parametro == "-d"){
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
		for (i = 0; (*dicionario)[i]->getC() != c; i++);
		ostringstream convert;
		convert << (*dicionario)[i]->getCod();
		string aux = convert.str();
		str = str + aux;
	}
	// cout << str;
	int aux = 0;
	string cod = "";
	for (i = 0; i < str.size(); i++){
		cod = cod + str[i];
		if (cod.size() >= 10){
			aux = atoi(cod.c_str());
			outFile.write((char*)&(aux), sizeof(aux));
			cod = "";
		}
	}
	if (cod.size() != 0){
			aux = atoi(cod.c_str());
			outFile.write((char*)&(aux), sizeof(aux));
	}
	// outFile.close();
}

void Huffman::dictionaryFromFile(){

}

void Huffman::uncompress(){
	if (testFile()){
		dictionaryFromFile();
		uncompressTexto();
	} else {
		cout << "uso: huffman.exe -parametro arquivoEntrada.txt arquivoSaida.txt" << endl;
	}
}

bool Huffman::testFile(){
	bool a, b, c;
	a = inFile.is_open();
	b = inFile_read.is_open();
	c = outFile.is_open();
	return a && b && c;
}

void Huffman::uncompressTexto(){
	// string str = "";
	// string aux;
	// text = "";
	// int i;
	// char c;
	// while (inFile.get(c)){
	// 	aux = c;
	// 	str = str + aux;
	// 	// converter int to string
	// 	for (i = 0; i < dicionario->size() && (*dicionario)[i]->getCod() != str ; i++);
	// 	if (i < dicionario->size()){
	// 		str = "";
	// 		if ((*dicionario)[i]->getC() != char(0) && (*dicionario)[i]->getC() != '\n'){
	// 			outFile.put((*dicionario)[i]->getC());
	// 		} else if ((*dicionario)[i]->getC() != '\n'){
	// 			outFile.put('\n');
	// 		}
	// 	}
	// }
}