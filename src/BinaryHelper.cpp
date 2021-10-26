#include "BinaryHelper.h"

unsigned int BinaryHelper::setBitToOne(unsigned int num)
{
	return ((num & mask) | mask_one);
}

unsigned int BinaryHelper::setBitToZero(unsigned int num)
{
	return ((num & mask) | mask_zero);
}

unsigned int BinaryHelper::getCurrentBit(unsigned int num)
{
	return (num & mask_one);
}

unsigned int BinaryHelper::parse_int(string str)
{
	unsigned int num = 0x00000000;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
		{
			num = setBitToOne(num);
		}
		else
		{
			num = setBitToZero(num);
		}
		if (i < str.size() - 1)
			num = num << 1;
	}
	return num;
}

string BinaryHelper::parse_str(unsigned int num)
{
	string str;
	unsigned int aux;
	for (int i = 0; i < 32; i++)
	{
		aux = getCurrentBit(num);
		stringstream ss;
		ss << aux;
		str = ss.str() + str;
		num = num >> 1;
	}
	return str;
}
