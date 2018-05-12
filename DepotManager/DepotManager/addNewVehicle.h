#pragma once
#include "Bus.h"
#include "Tramway.h"
#include "Trolleybus.h"

//-------------------

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

//-------------------

template <class VehicleType>
void verifyAndSave(VehicleType&);

template <class VehicleType>
void addNewVehicle()
{
	VehicleType newVehicle;

	newVehicle.readNameManufacturerAndDesignation();

	newVehicle.readEnginesPower();

	newVehicle.readSpeedMax();

	newVehicle.readPassenegerNum();

	newVehicle.readMeasurements();

	newVehicle.readSpecialProperties();

	newVehicle.createId();

	verifyAndSave(newVehicle);

	system("pause");
}

template <class VehicleType>
void verifyAndSave(VehicleType& newVehicle)
{
	fstream listOfVehicles;
	string p_str;
	char yn;
	bool run = true;

	system("cls");

	listOfVehicles.open("listOfVehicles.txt", ios::in);

	if (listOfVehicles.is_open())
	{
		while (listOfVehicles.good())
		{
			getline(listOfVehicles, p_str);

			if (p_str == newVehicle.id)
			{
				cout << "Pojazd o ID " << newVehicle.id << " istnieje juz w bazie!" << endl
					<< endl;

				while (run)
				{
					listOfVehicles.close();

					cout << "Czy chcesz, zeby zostal nadpisany? [T/N]: ";
					cin >> yn;

					switch (yn)
					{
					case 't':
					case 'T':
						newVehicle.saveToFile();

						cout << "Pojazd o ID " << newVehicle.id << " zostal nadpisany!" << endl;
						run = false;
						break;
					case 'n':
					case 'N':
						cout << "Pojazd o ID " << newVehicle.id << " nie zostal nadpisany!" << endl;
						run = false;
						break;
					default:
						break;
					}
				}
			}
			else if (listOfVehicles.eof())
			{
				listOfVehicles.close();
				listOfVehicles.open("listOfVehicles.txt", ios::out | ios::app);

				newVehicle.saveToFile();
				listOfVehicles << newVehicle.id << endl;

				cout << "Pojazd o ID " << newVehicle.id << " zostal zapisany!" << endl;

				listOfVehicles.close();

				break;
			}
		}
	}
	else cout << "Blad podczas otwierania listy ID pojzadow!" << endl;
}
