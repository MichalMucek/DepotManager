#include "displayAllVehicles.h"

bool displayAllVehicles()
{
	fstream listOfVehicles;
	fstream vehicleFile;

	int tramwaysNum = 0, i_tw = 0,
	    busesNum = 0, i_bs = 0,
	    trolleybusesNum = 0, i_tb = 0;

	string *tramwaysId,
	       *busesId,
	       *trolleybusesId,
	       readId,
	       vehicleType;

	Tramway p_tw;
	Bus p_bs;
	Trolleybus p_tb;

	listOfVehicles.open("listOfVehicles.txt", ios::in);

	if (listOfVehicles.is_open())
	{
		while (listOfVehicles.good())
		{
			getline(listOfVehicles, readId);

			vehicleType = readId.substr(0, 2);

			if (vehicleType == "Tw") tramwaysNum++;
			if (vehicleType == "Bs") busesNum++;
			if (vehicleType == "Tb") trolleybusesNum++;
		}
	}
	else
	{
		cout << "Plik zawierajacy ID pojazdow nie mogl zostac otwarty!" << endl
			<< endl;

		system("pause");
		return false;
	}

	listOfVehicles.close();

	tramwaysId = new string[tramwaysNum];
	busesId = new string[busesNum];
	trolleybusesId = new string[trolleybusesNum];

	listOfVehicles.open("listOfVehicles.txt", ios::in);

	if (listOfVehicles.is_open())
	{
		while (listOfVehicles.good())
		{
			getline(listOfVehicles, readId);

			vehicleType = readId.substr(0, 2);

			if (vehicleType == "Tw")
			{
				tramwaysId[i_tw] = readId;
				i_tw++;
			}

			if (vehicleType == "Bs")
			{
				busesId[i_bs] = readId;
				i_bs++;
			}

			if (vehicleType == "Tb")
			{
				trolleybusesId[i_tb] = readId;
				i_tb++;
			}
		}
	}
	else
	{
		cout << "Plik zawierajacy ID pojazdow nie mogl zostac otwarty!" << endl
			<< endl;

		system("pause");
		return false;
	}

	system("cls");

	cout << "/--=TRAMWAJE=--\\" << endl
		<< endl;

	if (tramwaysNum == 0) cout << "BRAK" << endl;

	for (int i = 0; i < tramwaysNum; i++)
	{
		p_tw = readFromFileToObject<Tramway>(tramwaysId[i]);

		cout << p_tw.name << " (" << p_tw.designation << ") - ";
		p_tw.sayStatus();
		cout << " - ID: " << p_tw.id << endl;
	}

	cout << endl
		<< endl
		<< endl
		<< "/--=AUTOBUSY=--\\" << endl
		<< endl;

	if (busesNum == 0) cout << "BRAK" << endl;

	for (int i = 0; i < busesNum; i++)
	{
		p_bs = readFromFileToObject<Bus>(busesId[i]);

		cout << p_bs.name << " (" << p_bs.designation << ") - ";
		p_bs.sayStatus();
		cout << " - ID: " << p_bs.id << endl;
	}

	cout << endl
		<< endl
		<< endl
		<< "/--=TROLEJBUSY=--\\" << endl
		<< endl;

	if (trolleybusesNum == 0) cout << "BRAK" << endl;

	for (int i = 0; i < trolleybusesNum; i++)
	{
		p_tb = readFromFileToObject<Trolleybus>(trolleybusesId[i]);

		cout << p_tb.name << " (" << p_tb.designation << ") - ";
		p_tb.sayStatus();
		cout << " - ID: " << p_tb.id << endl;
	}

	cout << endl << endl;
	system("pause");

	return true;
}
