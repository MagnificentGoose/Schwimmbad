#pragma once
class Heizung
{
private:
	int leistung;

public:
	Heizung();
	~Heizung();
	
	int getLeistung() { return leistung; }
	void aendereLeistung(int einheit);
};

