#include <chrono>
#include <thread>
#include "Steuerung.h"
#include <iostream>

using namespace std;

Steuerung::Steuerung(int sollTemp)
{
	sollTemp = 28;
	intervall = 10;
	alarm = "gruen";
	heizung = 0;

}

void Steuerung::ueberwache()
{ 
	int stufe = 0;
	for (int i = 0; i <= 2; i++) {

		int wert = wandler[i]->liesWert();
		if (wert < sollTemp) {
			stufe += 1;
			if (stufe == 1) {
				alarm = "gelb";
			}
			else if (stufe == 2) {
				alarm = "orange";
				intervall = 5;
				heizung += 1;
			}
			else if (stufe == 3) {
				alarm = "rot";
				intervall = 5;
				heizung += 2;
			}
		}
		else {
			alarm = "gruen";
			intervall = 10;
			heizung = 0;
		}
	}
	
}

int Steuerung::inCelsius(int d)
{
	int wert = 0;

	if (d > 210) {
		wert = -d + 230;
	}
	else {
		wert = 90 - 1 /(3*d);
	}
	return wert;
}

string Steuerung::getAlarm()
{
	return alarm;
}
