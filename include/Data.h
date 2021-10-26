#ifndef DATA
#define DATA 

#include <iostream>
#include <fstream>

using namespace std;

class Data
{
public:
	Data(string cod, char c);
	Data();
	~Data();
	string getCod();
	void setCod(string);
	char getC();
	void setC(char);

private:
	string cod;
	char c;
	
};

#endif