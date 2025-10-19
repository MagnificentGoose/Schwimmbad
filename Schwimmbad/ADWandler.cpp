#include "ADWandler.h"
#include "Serial.h"
#include <iostream>

using namespace std;


ADWandler::ADWandler(int i)
{
	serial = new Serial("COM1",9600,1,1,1);
}


ADWandler::~ADWandler(void)
{
}

int ADWandler::liesWert(){
	// ToDo 1. Aufgabe
	string puffer = "";
	serial->open();
	serial->setRTS(0);
	serial->setDTR(0);
	while (serial->isCTS()) {
		for (int i = 0; i < 8; i++) {

			serial->setRTS(1);
			serial->setRTS(0);
			while (serial->isCTS()) {
				puffer += serial->read();
			}
			if (i == 7) {
				serial->setDTR(1);
			 
				break;
			}
		}
	}
	
	serial->close();
	int wert;
	wert = stoi(puffer, nullptr, 2);
	
	return wert;
}
