#include "Heizung.h"


Heizung::Heizung()
{
	leistung = 0;
}


Heizung::~Heizung()
{
}

void Heizung::aendereLeistung(int einheit)
{
	leistung += einheit;

}
