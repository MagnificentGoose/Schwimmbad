#pragma once
#include <string>

using namespace std;

class Serial  
{
private:
  // Der Port-Name (COM1)
 string portName;
  int baudrate;
  int dataBits;
  int stopBits;
  int parity;

  // Z�hler nur f�r die Schwimmbeckenausfgabe!
  int zaehler;

  /** Handle f�r den Com-Port */
 // HANDLE handle;
public:
  Serial(string portName, int baudrate, int dataBits, int stopBits, int parity); // der Konstruktor Initialisiert die serielle Schnittstelle ohne sie zu �ffnen
  ~Serial();

  bool open(); 
  void close(); 

  int dataAvailable(); 

  int read(); 
  int read(unsigned char *buffer, int len); // statt (b: byte[], len: int)
  string readLine(); 
  void write(int value); 
  void write(unsigned char *buffer, int len); 
  void write(string s); 
  void setRTS(bool arg);
  void setDTR(bool arg);
  bool isCTS(); 
  bool isDSR(); 

  // Attribute f�r die Simulation einer Schnittstelle:

	unsigned char byte;				// speichert genau ein Byte
	unsigned char *bytesToWrite;	// speichert mehrere Bytes
	string s;						// speichert einen string
	bool simulationOpen;			// f�r R�ckgabe, ob die Schnittstelle wirklich ge�ffnet ist
	bool rts;
	bool dts;
	bool cts;
	bool dsr;
};
