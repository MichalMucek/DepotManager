#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Course
{
	string date_start, date_finish,
	       time_start, time_finish,
	       comments,
	       idOfVehicle;

	int lineNumber;

public:
	bool readCourse();
	void readCourseFromFile(fstream&);
	void saveCourseToFile();

	friend void addFinishedCourse();
	friend ostream& operator <<(ostream&, Course&);

	Course();
	~Course();
};
