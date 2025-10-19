
#include <Windows.h> // für DWORD
#include "Serial.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

Serial::Serial(string portName, int baudrate, int dataBits, int stopBits, int parity)
{
	this->portName = portName;
	this->baudrate = baudrate;
	this->dataBits = dataBits;
	this->stopBits = stopBits;
	this->parity = parity;
	// this->handle = INVALID_HANDLE_VALUE;

	// Attribute für die Simulation einer Schnittstelle:
	byte = NULL;
	bytesToWrite = NULL;
	s = "";
	simulationOpen = false;
	rts = true;
	dts = true;
	cts= false;
	dsr = false;

	zaehler = 0;

}

Serial::~Serial()
{
	// delete []bytesToWrite; // ???
}

// Schnittstelle öffnen - öffnet die serielle Schnittstelle; liefert true, wenn die Schnittstelle verwendbar ist.
bool Serial::open() {
	if(portName == "COM1" && baudrate == 9600 && dataBits == 1 && stopBits == 1 && parity == 1)
	{
		cout << "Schnittstelle geoeffnet" << endl;
		simulationOpen=true;
		return(true);
	}
	else
	{
		close();
		simulationOpen=false;
		return(false);
	}
}

// Schnittstelle schließen - schließt die serielle Schnittstelle; die Schnittstelle ist dann solange nicht mehr verwendbar, bis sie wieder geöffnet wird.
void Serial::close(void)
{
	cout << "Schnittstelle geschlossen" << endl;
}

// liefert die Anzahl der Byte, die von der seriellen Schnittstelle gelesen werden können
int Serial::dataAvailable()
{
	//COMSTAT comStat;
	//DWORD e;

	//if (handle != INVALID_HANDLE_VALUE)
	//  if (ClearCommError(handle, &e, &comStat))
	//    return comStat.cbInQue;
	return 0;
}

// schreibt ein Byte auf die serielle Schnittstelle; ist die Schnittstelle nicht geöffnet geschieht nichts.
// value: niederwertige 8 Bit werden übertragen
void Serial::write(int value)
{
	while(simulationOpen==false);  
	byte = value;
}

// schreibt mehrere Bytes auf die serielle Schnittstelle; ist die Schnittstelle nicht bereit geschieht nichts.
void Serial::write(unsigned char *buffer, int len)
{
	while(simulationOpen==false);

	bytesToWrite = new unsigned char[len];
	bytesToWrite = buffer;

}

// schreibt einen String auf die serielle Schnittstelle; ist die Schnittstelle nicht geöffnet geschieht nichts.
void Serial::write(string s)
{
	while(simulationOpen==false);  
	this->s = s;
}

// liest ein Byte (0..255) von der serielle Schnittstelle; Ist kein Byte verfügbar, liefert sie -1.
int Serial::read() 
{
	if(byte == NULL) 
		return (-1);
	else
		return (byte);
}


int Serial::read(unsigned char *buffer, int len)
{
	if(bytesToWrite == NULL)
		return (-1);

	int i=0;
	for(; i<len ; i++)
	{
		buffer[i]=bytesToWrite[i];
	}

	return (i);
}

string Serial::readLine()
{
	return s;
}

//-------------- Erweiterungen zum Setzen und Abfragen der Handshake-Leitungen

// setzt RTS-Leitung auf high (arg=true) oder low (aeg=false).
void Serial::setRTS(bool arg)
{
	rts = arg;
}

// setzt DTR-Leitung auf high (arg=true) oder low (arg=false).
void Serial::setDTR(bool arg)
{
	dts = arg;
}

// Modem-Statusinformationen ermitteln (hier CTS); wie getCTS
bool Serial::isCTS()
{
	bool x = 0;
	if (zaehler == 8) { zaehler = 1; }
	else zaehler++;

	if (zaehler >= 7) {
		//	cout << ".";
		x = 1;

	}
	else if ( zaehler == 4)
	{
		x = 0;
	}
	else
	{
		srand(time(NULL)); // Zufallsgenerator initialisieren 
		this_thread::sleep_for(std::chrono::milliseconds(250));
		x = rand() % 2;
	}
		cout << x;
	
	return x;
}

// Modem-Statusinformationen ermitteln (hier DSR); getDSR
bool Serial::isDSR()
{
	return dsr;
}
