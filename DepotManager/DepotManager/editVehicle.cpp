#include "editVehicle.h"

bool editVehicle(Vehicle* ptr_vehicle)
{
	string vehicleType("");
	int choice;
	bool run = true;

	vehicleType = ptr_vehicle->id.substr(0, 2);

	cout << "Edytuj..." << endl
		<< "1. Typ/nazwe, producenta, rok produkcji i oznaczenie" << endl
		<< "2. Moc silnikow" << endl
		<< "3. Predkosc maksymalna" << endl
		<< "4. Ilosc miejsc dla pasazerow" << endl
		<< "5. Mase wlasciwa oraz wymiary" << endl
		<< "6. Status" << endl;

	if (vehicleType == "Tw")
		cout << "7. Rozstaw szyn, napiecie zasilania i ilosc czlonow" << endl;

	if (vehicleType == "Bs")
		cout << "7. Pojemnosc baku oraz aktualna ilosc paliwa" << endl;

	if (vehicleType == "Tb")
		cout << "7. Napiecie zasilania" << endl;

	cout << "0. Powrot do menu glownego" << endl;

	while (run)
	{
		cout << endl
			<< "Podaj numer opcji [0-7]: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			return false;
			break;
		case 1:
			ptr_vehicle->resetNameEtc();
			ptr_vehicle->readNameManufacturerAndDesignation();
			run = false;
			break;
		case 2:
			ptr_vehicle->resetEnginesPower();
			ptr_vehicle->readEnginesPower();
			run = false;
			break;
		case 3:
			ptr_vehicle->resetSpeedMax();
			ptr_vehicle->readSpeedMax();
			run = false;
			break;
		case 4:
			ptr_vehicle->resetPassenegersNum();
			ptr_vehicle->readPassenegerNum();
			run = false;
			break;
		case 5:
			ptr_vehicle->resetMeasurements();
			ptr_vehicle->readMeasurements();
			run = false;
			break;
		case 6:
			ptr_vehicle->readStatus();
			run = false;
			break;
		case 7:
			ptr_vehicle->resetSpecialProperties();
			ptr_vehicle->readSpecialProperties();
			run = false;
			break;
		}
	}

	ptr_vehicle->saveToFile();

	cout << endl
		<< endl << "Zapisano zmiany!" << endl
		<< endl;

	system("pause");

	return true;
}
