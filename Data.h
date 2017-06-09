#ifndef DATA
#define DATA 

class Data
{
public:
	Data(int cod, char c);
	Data();
	~Data();
	int getCod();
	void setCod(int);
	char getC();
	void setC(char);

private:
	int cod;
	char c;
	
};

#endif