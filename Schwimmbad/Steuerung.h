#pragma once
#include <string>
#include "ADWandler.h"
#include "Heizung.h"

using namespace std;

class Steuerung
{
private:
	int sollTemp;
	int intervall;
	string alarm;
	ADWandler* wandler[3];
	Heizung* heizung;


public:
	Steuerung(int sollTemp);
	void ueberwache();
	static int inCelsius(int d);
	string getAlarm();
};



