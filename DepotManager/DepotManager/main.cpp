#include "readFromFileToObject.h"
#include "addNewVehicle.h"
#include "displayAllVehicles.h"
#include "editVehicle.h"
#include "addFinishedCourse.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Tramway.h"
#include "Trolleybus.h"
#include "Course.h"

//-------------------

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	bool run = true;
	int choice;
	string vehicleType(""), p_id("");

	Vehicle* ptr_vehicle = nullptr;
	Tramway p_tw;
	Bus p_bs;
	Trolleybus p_tb;

	while (run)
	{
		system("cls");

		cout << "PROGRAM DO ZARZADZANIA ZAJEZDNIA" << endl
			<< endl
			<< "1. Wyswietl liste wszystkich pojazdow" << endl
			<< "2. Wyswietl i edytuj dane wybranego pojazdu" << endl
			<< "3. Dodaj nowy pojazd" << endl
			<< "4. Wyswietl historie kursow wybranego pojazdu" << endl
			<< "5. Dodaj zakonczony kurs" << endl
			<< "0. ZAMKNIJ PROGRAM" << endl
			<< endl
			<< "Podaj numer opcji [0-5]: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			run = false;
			break;
		case 1:
			displayAllVehicles();
			break;
		case 2:
			system("cls");

			cout << "Podaj ID pojazdu: ";
			cin >> p_id;

			vehicleType = p_id.substr(0, 2);

			if (vehicleType == "Tw")
			{
				p_tw = readFromFileToObject<Tramway>(p_id);
				ptr_vehicle = &p_tw;
			}

			if (vehicleType == "Bs")
			{
				p_bs = readFromFileToObject<Bus>(p_id);
				ptr_vehicle = &p_bs;
			}

			if (vehicleType == "Tb")
			{
				p_tb = readFromFileToObject<Trolleybus>(p_id);
				ptr_vehicle = &p_tb;
			}

			if (ptr_vehicle == nullptr)
			{
				cout << endl << endl
					<< "Podane ID nie wskazuje na zaden wlasciwy rodzaj pojzadu!" << endl
					<< endl;

				system("pause");

				break;
			}
			ptr_vehicle->showInfo();
			editVehicle(ptr_vehicle);
			ptr_vehicle = nullptr;

			break;
		case 3:
			while (run)
			{
				system("cls");

				cout << "1. Tramwaj" << endl
					<< "2. Autobus" << endl
					<< "3. Trolejbus" << endl
					<< endl
					<< "Wybierz pojazd [1-3]: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					addNewVehicle<Tramway>();
					run = false;
					break;
				case 2:
					addNewVehicle<Bus>();
					run = false;
					break;
				case 3:
					addNewVehicle<Trolleybus>();
					run = false;
					break;
				}
			}

			run = true;
			break;
		case 4:
			system("cls");

			cout << "Podaj ID pojazdu: ";
			cin >> p_id;

			vehicleType = p_id.substr(0, 2);

			if (vehicleType == "Tw" || vehicleType == "Bs" || vehicleType == "Tb") displayHistoryOfVehicle(p_id);
			else
			{
				cout << endl << endl
					<< "Podane ID nie wskazuje na zaden wlasciwy rodzaj pojzadu!" << endl
					<< endl;

				system("pause");
			}
			break;
		case 5:
			addFinishedCourse();
			break;
		}
	}

	return 0;
}
