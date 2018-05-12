#include "Trolleybus.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

void Trolleybus::readSpecialProperties()
{
	system("cls");

	while (supplyVoltage <= 0)
	{
		cout << "Podaj napiecie zasilania [V]: ";
		cin >> supplyVoltage;
	}
}

void Trolleybus::createId()
{
	id = "Tb" + Vehicle::createId();
}

void Trolleybus::saveToFile()
{
	fstream file;
	string fileName;

	Vehicle::saveToFile();

	fileName = id + ".txt";

	file.open(fileName, ios::out | ios::app);

	file << supplyVoltage << endl;

	file.close();
}

void Trolleybus::resetSpecialProperties()
{
	supplyVoltage = 0;
}

void Trolleybus::showInfo()
{
	cout << "TROLEJBUS - ";

	Vehicle::showInfo();

	cout << endl
		<< endl << "NAPIECEIE ZASILANIA [V]: " << supplyVoltage << " V" << endl
		<< endl << endl;
}

void Trolleybus::readSpecialPropertiesFromFile(fstream& vehicleFile)
{
	string line;

	getline(vehicleFile, line);
	stringstream(line) >> supplyVoltage;
}

Trolleybus::Trolleybus()
{
	supplyVoltage = 0;
}

Trolleybus::~Trolleybus()
{
}
