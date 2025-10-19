#pragma once
#include <string>

using namespace std;

class Messung
{
private:
	string datumUhrzeit;
	int werte[3] = { 0 };

public: 
	Messung(int temp1, int temp2, int temp3);
	~Messung(void);
	


};

