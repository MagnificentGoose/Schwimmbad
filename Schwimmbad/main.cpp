#include "Serial.h"
#include "ADWandler.h"
#include "Steuerung.h"
#include <iostream>

using namespace std;

int main(){
	// 1. Aufgabe:
	ADWandler* test = new ADWandler(1);
	cout << test->liesWert() << endl;

	// 2. Aufgabe:
	Steuerung * s = new Steuerung(28);
	 
	// 3. Aufgabe:
	s->ueberwache();

	// 4. Aufgabe:
	// Klasse Ringpuffer testen!

	return 0;
}
