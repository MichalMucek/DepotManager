#include "displayHistoryOfVehicle.h"

bool displayHistoryOfVehicle(string givenId)
{
	Course p_course;
	Vehicle* ptr_vehicle = nullptr;
	fstream historyFile;
	string fileName(""), vehicleType("");

	Tramway p_tw;
	Bus p_bs;
	Trolleybus p_tb;

	fileName = "H" + givenId + ".txt";

	historyFile.open(fileName, ios::in);

	if (historyFile.is_open())
	{
		system("cls");

		cout << "HISTORIA KURSOW ";

		vehicleType = givenId.substr(0, 2);

		if (vehicleType == "Tw")
		{
			p_tw = readFromFileToObject<Tramway>(givenId);
			ptr_vehicle = &p_tw;
			cout << "TRAWAJU ";
		}

		if (vehicleType == "Bs")
		{
			p_bs = readFromFileToObject<Bus>(givenId);
			ptr_vehicle = &p_bs;
			cout << "AUTOBUSU ";
		}

		if (vehicleType == "Tb")
		{
			p_tb = readFromFileToObject<Trolleybus>(givenId);
			ptr_vehicle = &p_tb;
			cout << "TROLEJBUSU ";
		}

		cout << ptr_vehicle->name << " (" << ptr_vehicle->designation << ") - ID: " << ptr_vehicle->id << endl
			<< endl;

		historyFile.ignore(1, '\n');

		while (historyFile.good())
		{
			p_course.readCourseFromFile(historyFile);

			cout << p_course;
		}
	}
	else
	{
		cout << "Plik zawierajacy historie kursow pojazdu o ID " << givenId << " nie mogl zostac otwarty!" << endl
			<< endl;

		system("pause");
		return false;
	}

	system("pause");
	return true;
}

ostream& operator<<(ostream& out, Course& course)
{
	out << "WYJAZD: " << course.date_start << " | " << course.time_start << endl
		<< "POWROT: " << course.date_finish << " | " << course.time_finish << endl
		<< "LINIA: " << course.lineNumber << endl
		<< "DODATKOWE UWAGI: " << course.comments << endl
		<< endl;

	return out;
}
