#include "Data.h"

Data::Data(string cod, char c){
	this->cod = cod;
	this->c = c;
}

Data::Data(){
}

string Data::getCod(){
	return this->cod;
}

void Data::setCod(string value){
	this->cod = value;
}

char Data::getC(){
	return this->c;
}

void Data::setC(char value){
	this->c = value;
}