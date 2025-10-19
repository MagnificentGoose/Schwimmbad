#pragma once
class Serial;

class ADWandler
{
private:
	Serial *serial;
public:
	ADWandler(int i);
	~ADWandler(void);

	int liesWert();
};

