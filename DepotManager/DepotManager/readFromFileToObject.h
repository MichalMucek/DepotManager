#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Tramway.h"
#include "Bus.h"
#include "Trolleybus.h"

using namespace std;

template <class VehicleType>
VehicleType readFromFileToObject(string givenId)
{
	fstream vehicleFile;
	string fileName, line;

	VehicleType vehicle;

	fileName = givenId + ".txt";

	vehicleFile.open(fileName, ios::in);

	if (vehicleFile.is_open())
	{
		getline(vehicleFile, vehicle.id);
		getline(vehicleFile, vehicle.name);
		getline(vehicleFile, vehicle.manufacturer);

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.yearOfProduction;

		getline(vehicleFile, vehicle.designation);

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.enginesNum;

		vehicle.enginesPower = new double[vehicle.enginesNum];

		getline(vehicleFile, line);

		switch (line[0])
		{
		case '0':
			vehicle.unitOfPower = W;
			break;
		case '1':
			vehicle.unitOfPower = kW;
			break;
		case '2':
			vehicle.unitOfPower = MECHANICAL_hp;
			break;
		case '3':
			vehicle.unitOfPower = ELECTRICAL_hp;
			break;
		}

		for (int i = 0; i < vehicle.enginesNum; i++)
		{
			getline(vehicleFile, line);
			stringstream(line) >> vehicle.enginesPower[i];
		}

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.speedMax;

		getline(vehicleFile, line);

		switch (line[0])
		{
		case '0':
			vehicle.unitOfSpeed = kmph;
			break;
		case '1':
			vehicle.unitOfSpeed = mph;
			break;
		}

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.seatsNum;

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.standingPlacesNum;

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.passenegersMax;

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.weight;

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.length;

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.width;

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.height;

		getline(vehicleFile, line);
		stringstream(line) >> vehicle.entriesNum;

		vehicle.floorHeights = new int[vehicle.entriesNum];

		for (int i = 0; i < vehicle.entriesNum; i++)
		{
			getline(vehicleFile, line);
			stringstream(line) >> vehicle.floorHeights[i];
		}

		getline(vehicleFile, line);

		switch (line[0])
		{
		case '0':
			vehicle.status = ON_ROUTE;
			break;
		case '1':
			vehicle.status = READY_FOR_THE_COURSE;
			break;
		case '2':
			vehicle.status = IN_MAINTENANCE;
			break;
		case '3':
			vehicle.status = DAMAGED;
			break;
		}

		vehicle.readSpecialPropertiesFromFile(vehicleFile);
	}
	else
	{
		cout << endl << "Plik z danymi pojazdu o ID " << givenId << " nie mogl zostac otwarty!" << endl
			<< endl << endl;

		system("pause");
	}

	vehicleFile.close();

	return vehicle;
}
