#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

//--------------------

void Vehicle::readNameManufacturerAndDesignation()
{
	system("cls");

	cin.ignore(1, '\n');

	cout << "TYP/NAZWA: ";

	getline(cin, name);

	cout << "NAZWA PRODUCENTA: ";
	getline(cin, manufacturer);

	while (yearOfProduction <= 1800)
	{
		cout << "ROK PRODUKCJI: ";
		cin >> yearOfProduction;
	}

	cin.ignore(1, '\n');

	cout << "OZNACZENIA: ";

	getline(cin, designation);
}

void Vehicle::readEnginesPower()
{
	bool run = true;
	char choice = 0;

	system("cls");

	while (enginesNum <= 0)
	{
		cout << "ILOSC SILNIKOW: ";
		cin >> enginesNum;
	}

	enginesPower = new double[enginesNum];

	cout << endl;

	if (enginesNum == 1)
	{
		cout << "MOC SILNIKA: ";
		cin >> enginesPower[0];
	}
	else
	{
		cout << "MOC SILNIKOW: " << endl;

		for (int i = 0; i < enginesNum; i++)
		{
			enginesPower[i] = 0;

			while (enginesPower[i] <= 0)
			{
				cout << "\tSILNIK NR " << i + 1 << ": ";
				cin >> enginesPower[i];
			}
		}
	}

	cout << endl
		<< "----------" << endl
		<< endl
		<< "1. WATT (W)" << endl
		<< "2. KILOWATT (kW)" << endl
		<< "3. KON MECHANICZNY (KM)" << endl
		<< "4. ELEKTRYCZNY KON MECHANICZNY (ELEKTR. KM)" << endl
		<< endl;

	while (run)
	{
		cout << "JEDNOSTKA ";
		if (enginesNum == 1) cout << "PODANEJ MOCY [1-4]: ";
		else cout << "PODANYCH MOCY [1-4]: ";

		cin >> choice;

		switch (choice)
		{
		case '1':
			unitOfPower = W;
			run = false;
			break;
		case '2':
			unitOfPower = kW;
			run = false;
			break;
		case '3':
			unitOfPower = MECHANICAL_hp;
			run = false;
			break;
		case '4':
			unitOfPower = ELECTRICAL_hp;
			run = false;
			break;
		}
	}
}

void Vehicle::readSpeedMax()
{
	system("cls");

	bool run = true;
	int choice = 0;

	while (speedMax <= 0)
	{
		cout << "PREDKOSC MAKSYMALNA: ";
		cin >> speedMax;
	}

	cout << endl
		<< "----------" << endl
		<< endl
		<< "1. KM/H" << endl
		<< "2. MPH" << endl
		<< endl;

	while (run)
	{
		cout << "JEDNOSTKA PODANEJ PREDKOSCI MAKSYMALNEJ [1-2]: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			unitOfSpeed = kmph;
			run = false;
			break;
		case 2:
			unitOfSpeed = mph;
			run = false;
			break;
		}
	}
}

void Vehicle::readPassenegerNum()
{
	system("cls");

	while (seatsNum <= 0)
	{
		cout << "ILOSC MIEJSC SIEDZACYCH: ";
		cin >> seatsNum;
	}

	while (standingPlacesNum <= 0)
	{
		cout << "ILOSC MIEJSC STOJACYCH: ";
		cin >> standingPlacesNum;
	}

	passenegersMax = seatsNum + standingPlacesNum;

	cout << endl << "MAKSYMALNA ILOSC PASAZEROW WYNOSI " << passenegersMax << endl
		<< endl;

	system("pause");
}

void Vehicle::readMeasurements()
{
	system("cls");

	while (weight <= 0)
	{
		cout << "MASA WLASNA[kg]: ";
		cin >> weight;
	}

	while (length <= 0)
	{
		cout << "DLUGOSC [mm]: ";
		cin >> length;
	}

	while (width <= 0)
	{
		cout << "SZEROKOSC [mm]: ";
		cin >> width;
	}

	while (height <= 0)
	{
		cout << "WYSOKOSC [mm]: ";
		cin >> height;
	}

	while (entriesNum <= 0)
	{
		cout << "ILOSC WEJSC: ";
		cin >> entriesNum;
	}

	floorHeights = new int[entriesNum];

	cout << endl << "WYSOKOSC PODLOGI PRZY WEJSCIACH [mm]:" << endl;

	for (int i = 0; i < entriesNum; i++)
	{
		floorHeights[i] = 0;

		while (floorHeights[i] <= 0)
		{
			cout << "\tWEJSCIE NR " << i + 1 << ": ";
			cin >> floorHeights[i];
		}
	}
}

void Vehicle::readStatus()
{
	bool run = true;
	int choice;

	while (run)
	{
		system("cls");

		cout << "1. NA TRASIE" << endl
			<< "2. GOTOWY DO KURSOWANIA" << endl
			<< "3. W SERWISIE" << endl
			<< "4. USZKODZONY" << endl
			<< endl;

		cout << "PODAJ STATUS POJAZDU [1-4]: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			status = ON_ROUTE;
			run = false;
			break;
		case 2:
			status = READY_FOR_THE_COURSE;
			run = false;
			break;
		case 3:
			status = IN_MAINTENANCE;
			run = false;
			break;
		case 4:
			status = DAMAGED;
			run = false;
			break;
		}
	}
}

void Vehicle::readSpecialProperties()
{
}

void Vehicle::resetNameEtc()
{
	name = "";
	manufacturer = "";
	designation = "";
	yearOfProduction = 1800;
}

void Vehicle::resetEnginesPower()
{
	enginesNum = 0;
	delete[] enginesPower;
}

void Vehicle::resetSpeedMax()
{
	speedMax = 0;
}

void Vehicle::resetPassenegersNum()
{
	seatsNum = 0;
	standingPlacesNum = 0;
	passenegersMax = 0;
}

void Vehicle::resetMeasurements()
{
	weight = 0;
	length = 0;
	width = 0;
	height = 0;

	delete[] floorHeights;
	entriesNum = 0;
}

void Vehicle::resetSpecialProperties()
{
}

void Vehicle::sayStatus()
{
	switch (status)
	{
	case ON_ROUTE:
		cout << "NA TRASIE";
		break;
	case READY_FOR_THE_COURSE:
		cout << "GOTOWY DO KURSOWANIA";
		break;
	case IN_MAINTENANCE:
		cout << "W SERWISIE";
		break;
	case DAMAGED:
		cout << "USZKODZONY";
		break;
	default:
		cout << "(NIEZNANY / BRAK DANYCH)";
		break;
	}
}

void Vehicle::showInfo()
{
	system("cls");

	string unitOfPower_str("");

	cout << "ID: " << id << endl
		<< "TYP/NAZWA: " << name << endl
		<< "PRODUCENT: " << manufacturer << endl
		<< "ROK PRODUKCJI: " << yearOfProduction << endl
		<< "OZNACZENIE: " << designation << endl
		<< "ILOSC SILNIKOW: " << enginesNum << endl;

	//JEDNOSTKA MOCY

	switch (unitOfPower)
	{
	case W:
		unitOfPower_str = "W";
		break;
	case kW:
		unitOfPower_str = "kW";
		break;
	case MECHANICAL_hp:
		unitOfPower_str = "KM";
		break;
	case ELECTRICAL_hp:
		unitOfPower_str = "Elektryczny kon mechaniczny";
		break;
	}

	for (int i = 0; i < enginesNum; i++)
		cout << "\tSILNIK NR " << i + 1 << ": " << enginesPower[i] << " " << unitOfPower_str << endl;


	cout << "MAKSYMALNA PREDKOSC: " << speedMax;

	switch (unitOfSpeed)
	{
	case kmph:
		cout << " km/h" << endl;
		break;
	case mph:
		cout << " mph" << endl;
		break;
	}

	cout << "ILOSC MIEJSC SIEDZACYCH: " << seatsNum << endl
		<< "ILOSC MIEJSC STOJACYCH: " << standingPlacesNum << endl
		<< "MAKSYMALNA LICZBA PASAZEROW: " << passenegersMax << endl
		<< "MASA WLASNA: " << weight << " kg" << endl
		<< "DLUGOSC: " << length << " mm" << endl
		<< "SZEROKOSC: " << width << " mm" << endl
		<< "WYSOKOSC: " << height << " mm" << endl
		<< "ILOSC WEJSC: " << entriesNum << endl;

	for (int i = 0; i < entriesNum; i++)
		cout << "\tWEJSCIE NR " << i + 1 << ": " << floorHeights[i] << " mm" << endl;

	cout << endl
		<< "STATUS: ";
	sayStatus();
}

string Vehicle::createId()
{
	string partOfId("");

	partOfId = to_string(yearOfProduction);

	partOfId = partOfId + designation;

	return partOfId;
}

void Vehicle::saveToFile()
{
	fstream file;
	string fileName;

	fileName = id + ".txt";

	file.open(fileName, ios::out | ios::trunc);

	file << id << endl
		<< name << endl
		<< manufacturer << endl
		<< yearOfProduction << endl
		<< designation << endl
		<< enginesNum << endl
		<< unitOfPower << endl;

	for (int i = 0; i < enginesNum; i++)
		file << enginesPower[i] << endl;


	file << speedMax << endl
		<< unitOfSpeed << endl
		<< seatsNum << endl
		<< standingPlacesNum << endl
		<< passenegersMax << endl
		<< weight << endl
		<< length << endl
		<< width << endl
		<< height << endl
		<< entriesNum << endl;

	for (int i = 0; i < entriesNum; i++)
		file << floorHeights[i] << endl;

	file << status << endl;

	file.close();
}

Vehicle::Vehicle()
{
	id = "";

	name = "";
	manufacturer = "";
	designation = "";
	yearOfProduction = 1800;

	enginesNum = 0;
	unitOfPower = kW;

	speedMax = 0;
	unitOfSpeed = kmph;

	passenegersMax = 0;
	seatsNum = 0;
	standingPlacesNum = 0;
	entriesNum = 0;

	weight = 0;
	length = 0;
	width = 0;
	height = 0;

	status = READY_FOR_THE_COURSE;
}

Vehicle::~Vehicle()
{
}
