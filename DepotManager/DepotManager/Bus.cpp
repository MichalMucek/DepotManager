#include "Bus.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

void Bus::readSpecialProperties()
{
	system("cls");

	while (fuelMax <= 0)
	{
		cout << "POJEMNOSC BAKU [l]: ";
		cin >> fuelMax;
	}

	while (fuelCurrent < 0 || fuelCurrent > fuelMax)
	{
		cout << "AKTUALNA ILOSC PALIWA [l]: ";
		cin >> fuelCurrent;
	}
}

void Bus::createId()
{
	id = "Bs" + Vehicle::createId();
}

void Bus::resetSpecialProperties()
{
	fuelMax = 0;
	fuelCurrent = -1;
}

void Bus::showInfo()
{
	cout << "AUTOBUS - ";

	Vehicle::showInfo();

	cout << endl
		<< endl << "POJEMNOSC BAKU: " << fuelMax << " l" << endl
		<< "OBECNA ILOSC PALIWA: " << fuelCurrent << " l" << endl
		<< endl << endl;
}

void Bus::saveToFile()
{
	fstream file;
	string fileName;

	Vehicle::saveToFile();

	fileName = id + ".txt";

	file.open(fileName, ios::out | ios::app);

	file << fuelMax << endl
		<< fuelCurrent << endl;

	file.close();
}

void Bus::readSpecialPropertiesFromFile(fstream& vehicleFile)
{
	string line;

	getline(vehicleFile, line);
	stringstream(line) >> fuelMax;

	getline(vehicleFile, line);
	stringstream(line) >> fuelCurrent;
}

Bus::Bus()
{
	fuelMax = 0;
	fuelCurrent = -1;
}

Bus::~Bus()
{
}
