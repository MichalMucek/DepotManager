#include "Tramway.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>


void Tramway::readSpecialProperties()
{
	system("cls");

	while (trackGauge <= 0)
	{
		cout << "ROZSTAW SZYN [mm]: ";
		cin >> trackGauge;
	}

	while (supplyVoltage <= 0)
	{
		cout << "NAPIECIE ZASILANIA [V]: ";
		cin >> supplyVoltage;
	}

	while (segmentsNum <= 0)
	{
		cout << "ILOSC CZLONOW: ";
		cin >> segmentsNum;
	}
}

void Tramway::readSpecialPropertiesFromFile(fstream& vehicleFile)
{
	string line;

	getline(vehicleFile, line);
	stringstream(line) >> trackGauge;

	getline(vehicleFile, line);
	stringstream(line) >> supplyVoltage;

	getline(vehicleFile, line);
	stringstream(line) >> segmentsNum;
}

void Tramway::createId()
{
	id = "Tw" + Vehicle::createId();
}

void Tramway::resetSpecialProperties()
{
	trackGauge = 1435;
	supplyVoltage = 0;
	segmentsNum = 0;
}

void Tramway::showInfo()
{
	cout << "TRAMWAJ - ";

	Vehicle::showInfo();

	cout << endl
		<< endl << "ROZSTAW SZYN: " << trackGauge << " mm" << endl
		<< "NAPIECIE ZASILANIA: " << supplyVoltage << " V" << endl
		<< "ILOSC CZLONOW: " << segmentsNum << endl
		<< endl << endl;
}

void Tramway::saveToFile()
{
	fstream file;
	string fileName;

	Vehicle::saveToFile();

	fileName = id + ".txt";

	file.open(fileName, ios::out | ios::app);

	file << trackGauge << endl
		<< supplyVoltage << endl
		<< segmentsNum << endl;

	file.close();
}

Tramway::Tramway()
{
	trackGauge = 0;
	supplyVoltage = 0;
	segmentsNum = 0;
}

Tramway::~Tramway()
{
}
