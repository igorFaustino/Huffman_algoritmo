#include "binario.h"

binario::binario(){
	this->num = 0x00000000;
}

unsigned int binario::converter_int(string str){
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '1'){
			num = ((num & mascara) | mascara_um);
		} else {
			num = ((num & mascara) | mascara_zero);
		}
		if (i < str.size() - 1)
			num = num << 1;
	}
	return num;
}

string binario::converter_str(unsigned int num){
	string str;
	unsigned int aux;
	for(int i = 0; i < 32; i++){
		aux = (num & mascara_um);
		stringstream ss;
		ss << aux;
		str = ss.str() + str;
		num = num >> 1;
	}
	return str;
}