#ifndef BINARY
#define BINARY 
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class binario
{
public:
	binario();
	~binario();
	unsigned int converter_int(string);
	string converter_str(unsigned int num);
private:
	static const unsigned int mascara_um = 0x00000001;
	static const unsigned int mascara_zero = 0x00000000;
	static const unsigned int mascara = 0xfffffffe;
	unsigned int num;


};

#endif