#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;

Data::Data(int cod, char c){
	this->cod = cod;
	this->c = c;
}


int Data::getCod(){
	return this->cod;
}

void Data::setCod(int value){
	this->cod = value;
}

char Data::getC(){
	return this->c;
}

void Data::setC(char value){
	this->c = value;
}