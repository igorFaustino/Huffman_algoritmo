#ifndef BINARY
#define BINARY
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class BinaryHelper
{
public:
	static unsigned int parse_int(string);
	static string parse_str(unsigned int num);

private:
	static const unsigned int mask_one = 0x00000001;
	static const unsigned int mask_zero = 0x00000000;
	static const unsigned int mask = 0xfffffffe;

	static unsigned int setBitToOne(unsigned int num);
	static unsigned int setBitToZero(unsigned int num);
	static unsigned int getCurrentBit(unsigned int num);
};

#endif
