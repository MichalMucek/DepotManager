#include "Course.h"


bool Course::readCourse()
{
	bool id_isTrue = false;

	fstream listOfVehicles;
	string readIdOfVehicle("");

	system("cls");

	listOfVehicles.open("listOfVehicles.txt", ios::in);

	if (listOfVehicles.is_open())
	{
		while (!id_isTrue)
		{
			cout << "Podaj ID pojzadu: ";
			cin >> idOfVehicle;

			while (listOfVehicles.good())
			{
				listOfVehicles >> readIdOfVehicle;

				if (readIdOfVehicle == idOfVehicle)
				{
					id_isTrue = true;
					break;
				}
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

	listOfVehicles.close();

	if (id_isTrue)
	{
		cout << "DODAWANIE KURSU" << endl
			<< endl;

		cout << "Dzien wyjazdu z zajezdni [DD-MM-RRRR]: ";
		cin >> date_start;
		cout << "Godzina wyjazdu z zajezdni [GG:MM]: ";
		cin >> time_start;
		cout << endl
			<< "Dzien powrotu do zajezdni [DD-MM-RRRR]: ";
		cin >> date_finish;
		cout << "Godzina powortu do zajezdni [GG:MM]: ";
		cin >> time_finish;
		cout << endl;

		while (lineNumber < 0)
		{
			cout << "Linia, na ktorej kursowal pojazd: ";
			cin >> lineNumber;
		}

		cin.ignore(1, '\n');

		cout << endl
			<< "Dodatkowe uwagi: ";
		getline(cin, comments);

		if (comments == "") comments = "BRAK";
	}
	else
	{
		cout << endl << endl << "Pojazd o ID " << idOfVehicle << " nie istnieje w bazie!";
		return false;
	}

	return true;
}

void Course::saveCourseToFile()
{
	fstream historyFile;
	string historyFileName("");

	historyFileName = "H" + idOfVehicle + ".txt";

	historyFile.open(historyFileName, ios::out | ios::app);

	historyFile << endl
		<< date_start << " " << time_start << endl
		<< date_finish << " " << time_finish << endl
		<< lineNumber << endl
		<< comments;

	historyFile.close();

	system("cls");

	cout << "Kurs zostal zapisany!"
		<< endl << endl;
	system("pause");
}

void Course::readCourseFromFile(fstream& historyFile)
{
	string line;

	historyFile >> date_start >> time_start
		>> date_finish >> time_finish;

	historyFile >> line;
	stringstream(line) >> lineNumber;

	historyFile.ignore(1, '\n');

	getline(historyFile, comments);
}

Course::Course()
{
	date_start = "01-01-2000";
	date_finish = "01-01-2000";

	time_start = "00:00";
	time_finish = "00:00";

	comments = "";

	idOfVehicle = "";

	lineNumber = -1;
}

Course::~Course()
{
}
